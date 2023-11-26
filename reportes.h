#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


///PUNTO 1 ************************************************

class Punto1{
    private:
    int id;
    char nombre[30];
    int integrantes;
    bool estado;

public:

    void setId(int i){id=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setIntegrantes(int i){integrantes=i;}
    void setEstado(bool e){estado=e;}

    int getId(){return id;}
    const char *getNombre(){return nombre;}
    int getIntegrantes(){return integrantes;}
    int getEstado(){return estado;}

    void Mostrar(){
            cout<<"ID: ";
            cout<<id<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"INTEGRANTES ALUMNOS: ";
            cout<<integrantes<<endl;
            cout<<endl;
    }
};


class ArchivoPunto1{
private:
    char nombre[30];
public:
    ArchivoPunto1(const char *n){
        strcpy(nombre, n);
    }

    const char *getNombre(){return nombre;}

    bool agregarRegistro(Punto1 reg);
    bool listarRegistros();
    int contarRegistros();
    Punto1 leerRegistro(int pos);

    void vaciar(){
        FILE *p = fopen(nombre, "wb");
        if (p == NULL){return ;}
        fclose(p);
    }

};

int ArchivoPunto1::contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return 0;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Punto1);
		}

bool ArchivoPunto1::listarRegistros(){
    Punto1 reg;
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

bool ArchivoPunto1::agregarRegistro(Punto1 reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    bool escribio=fwrite(&reg,sizeof reg,1,p);

    fclose(p);
    return escribio;

}

Punto1 ArchivoPunto1::leerRegistro(int pos){
    Punto1 reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }

    fseek(p,sizeof(Punto1)*pos,0);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    return reg;

}

int buscarJugadores(int id){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    int tam=archi.contarRegistros();
    int cont=0;

    for(int i=0;i<tam;i++){
        reg=archi.leerRegistro(i);
        if(reg.getEquipo()==id &&reg.getEstado() &&reg.getClaustro()==2){
            cont++;
        }
    }
    return cont;
}

void guardarRegistro(Equipo eq,int cant){
    Punto1 reg;
    ArchivoPunto1 archi("punto1.dat");
    archi.vaciar();
    reg.setId(eq.getId());
    reg.setNombre(eq.getNombre());
    reg.setIntegrantes(cant);
    archi.agregarRegistro(reg);

}

void mostrarRegistro(){
    ArchivoPunto1 archi("punto1.dat");
    cout<<"EQUIPOS CON MAXIMO 5 INTEGRANTES ALUMNOS: "<<endl;
    archi.listarRegistros();
}



void ejercicio1(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int tam=archi.contarRegistros();
    int cant;

    for(int i=0;i<tam;i++){
        reg=archi.leerRegistro(i);
        cant=buscarJugadores(reg.getId());
        if(cant>0 && cant<6 && reg.getEstado()){
            guardarRegistro(reg,cant);
        }
    }
    mostrarRegistro();
    return;
}


///PUNTO 2 **********************************************


bool hayJugadores(int id){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    int tam=archi.contarRegistros();

    for(int i=0;i<tam;i++){
        reg=archi.leerRegistro(i);
        if(reg.getDeporte()==id &&reg.getEstado()){
            return true;
        }
    }
    return false;
}


void ejercicio2(){
    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int tam=archi.contarRegistros();
    bool aux=false;
    cout<<"DEPORTES SIN JUGADORES: "<<endl;
    for(int i=0;i<tam;i++){
        reg=archi.leerRegistro(i);
        if(!hayJugadores(reg.getId()) &&reg.getEstado()){
            reg.Mostrar();
            aux=true;
            cout<<endl;
        }
    }
    if(!aux){
        cout<<"NO HAY DEPORTE SIN JUGADORES"<<endl;
    }

}

/// PUNTO 3 **********************************************

void cargarVector(Punto1 *v,int tam){
    Punto1 reg;
    ArchivoPunto1 archi("punto1.dat");
    for(int i=0;i<tam;i++){
        reg=archi.leerRegistro(i);
        v[i]=reg;
    }
}


void mostrarVector(Punto1 *v,int tam){
    cout<<"VECTOR DINAMICO CREADO:"<<endl<<endl;
    for(int i=0;i<tam;i++){
        v[i].Mostrar();
        cout<<endl<<endl;
    }
}


void ejercicio3(){
    Punto1 reg;
    ArchivoPunto1 archi("punto1.dat");
    int tam=archi.contarRegistros();
    if(tam==0){
        cout<<"NO HAY REGISTROS"<<endl;
        return;
    }

    Punto1 *v;

    v=new Punto1[tam];
    if(v==nullptr){
        cout<<"ERROR AL RESERVAR MEMORIA PARA EL VECTOR"<<endl;
        return;
    }
    cargarVector(v,tam);
    mostrarVector(v, tam);
    delete[] v;

}

#endif // REPORTES_H_INCLUDED
