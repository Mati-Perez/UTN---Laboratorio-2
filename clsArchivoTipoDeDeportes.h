#ifndef CLSARCHIVOTIPODEDEPORTES_H_INCLUDED
#define CLSARCHIVOTIPODEDEPORTES_H_INCLUDED

class ArchivoTipoDeporte{
private:
    char nombre[30];
public:
    ArchivoTipoDeporte(const char *nTip){
        strcpy(nombre, nTip);
    }

    const char *getNombre(){return nombre;}

    bool agregarRegistro(TipoDeporte tip);
    bool listarRegistros();
    int contarRegistros();
    TipoDeporte leerRegistro(int pos);
    int buscarId(int d);
    bool modificarRegistro(int pos,TipoDeporte reg);

};

int ArchivoTipoDeporte::contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return 0;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(TipoDeporte);
		}

bool ArchivoTipoDeporte::listarRegistros(){
    TipoDeporte reg;
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

bool ArchivoTipoDeporte::agregarRegistro(TipoDeporte reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);

    fclose(p);
    return escribio;
}

TipoDeporte ArchivoTipoDeporte::leerRegistro(int pos){
    TipoDeporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(TipoDeporte)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}

bool ArchivoTipoDeporte::modificarRegistro(int pos,TipoDeporte reg){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,sizeof(TipoDeporte)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoTipoDeporte::buscarId(int d){
    TipoDeporte reg;

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

#endif // CLSARCHIVOTIPODEDEPORTES_H_INCLUDED
