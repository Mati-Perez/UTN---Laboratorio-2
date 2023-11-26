#ifndef CLSARCHIVOJUGADORES_H_INCLUDED
#define CLSARCHIVOJUGADORES_H_INCLUDED

class ArchivoJugador{
private:
    char nombre[30];
public:
    ArchivoJugador(const char *nJug){
        strcpy(nombre, nJug);
    }

    const char *getNombre(){return nombre;}

    bool agregarRegistro(Jugador jug);
    bool listarRegistros();
    int contarRegistros();
    Jugador leerRegistro(int pos);
    int buscarDNI(int dni);

    bool modificarRegistro(int pos,Jugador reg);

};

int ArchivoJugador::contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return -1;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Jugador);
		}

bool ArchivoJugador::listarRegistros(){
    Jugador reg;
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

bool ArchivoJugador::agregarRegistro(Jugador reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

}



int ArchivoJugador::buscarDNI(int dni){
    Jugador reg;

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof (Jugador),1,p)==1){
        if(reg.getDNI()==dni&&reg.getEstado()){
            fclose(p);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(p);
    return -1;
}

Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Jugador)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}

bool ArchivoJugador::modificarRegistro(int pos,Jugador reg){

    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    fseek(p,sizeof(Jugador)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;
}



#endif // CLSARCHIVOJUGADORES_H_INCLUDED
