#ifndef CLSARCHIVODEPORTES_H_INCLUDED
#define CLSARCHIVODEPORTES_H_INCLUDED


class ArchivoDeporte{
private:
    char nombre[30];
public:
    ArchivoDeporte(const char *nDep){
        strcpy(nombre, nDep);

    }

    const char *getNombre(){return nombre;}

    bool agregarRegistro(Deporte dep);
    bool listarRegistros();
    int contarRegistros();
    Deporte leerRegistro(int pos);
    int buscarId(int d);
    bool modificarRegistro(int pos,Deporte reg);

};

int ArchivoDeporte::contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return 0;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Deporte);
		}

bool ArchivoDeporte::listarRegistros(){
    Deporte reg;
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

bool ArchivoDeporte::agregarRegistro(Deporte reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);

    fclose(p);
    return escribio;

}


int ArchivoDeporte::buscarId(int d){
    Deporte reg;

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof (Deporte),1,p)==1){
        if(reg.getId()==d&&reg.getEstado()){
            fclose(p);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(p);
    return -1;
}

Deporte ArchivoDeporte::leerRegistro(int pos){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return reg;
    }

    fseek(p,sizeof(Deporte)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}

bool ArchivoDeporte::modificarRegistro(int pos,Deporte reg){

    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        return false;
    }


    fseek(p,sizeof(Deporte)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;


}




#endif // CLSARCHIVODEPORTES_H_INCLUDED
