#ifndef CLSARCHIVOEQUIPOS_H_INCLUDED
#define CLSARCHIVOEQUIPOS_H_INCLUDED

class ArchivoEquipo{
private:
    char nombre[30];
public:
    ArchivoEquipo(const char *nEq){
        strcpy(nombre, nEq);
    }

    const char *getNombre(){return nombre;}

    bool agregarRegistro(Equipo eq);
    bool listarRegistros();
    int contarRegistros();
    Equipo leerRegistro(int pos);
    int buscarId(int d);
    bool modificarRegistro(int pos,Equipo reg);

};

int ArchivoEquipo::contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return 0;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Equipo);
		}

bool ArchivoEquipo::listarRegistros(){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

bool ArchivoEquipo::agregarRegistro(Equipo reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);

    fclose(p);
    return escribio;

}

Equipo ArchivoEquipo::leerRegistro(int pos){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Equipo)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}

bool ArchivoEquipo::modificarRegistro(int pos,Equipo reg){

    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    fseek(p,sizeof(Equipo)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;


}
int ArchivoEquipo::buscarId(int d){
    Equipo reg;

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof (Equipo),1,p)==1){
        if(reg.getId()==d&&reg.getEstado()){
            fclose(p);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(p);
    return -1;
}

#endif // CLSARCHIVOEQUIPOS_H_INCLUDED
