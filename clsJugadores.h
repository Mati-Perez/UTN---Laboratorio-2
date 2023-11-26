#ifndef CLSJUGADORES_H_INCLUDED
#define CLSJUGADORES_H_INCLUDED

class Jugador{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int deporte;
    int equipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;

public:
    ///CONSTRUCTORES
        Jugador(const char *n="NOMBRE"){
            strcpy(nombre,n);
            estado=true;
        }
    //*************************************
        Jugador(int d, int m, int a){
            fechaInscripcion.setDia(d);
            fechaInscripcion.setMes(m);
            fechaInscripcion.setAnio(a);
            estado=true;
        }
    //*************************************
        Jugador(Fecha aux){
            fechaInscripcion=aux;
            estado=true;
        }

    bool operator>(const char *cad){
    if(strcmp(this->apellido,cad)>0) return true;
    return false;}
/// GETTERS**************************************************
    int getDNI(){return DNI;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    bool getEstado(){return estado;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getEquipo(){return equipo;}
    float getMatricula(){return matricula;}

///SETTERS*****************************************************
    void setDNI(const int d){DNI=d;}
    void setFechaInscripcion(Fecha f){
        fechaInscripcion=f;
        }
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setEstado(bool e){estado=e;}
    void setClaustro(int c){
        if(c>0&&c<5) claustro=c;
        else claustro=-1;}
    void setDeporte(int dep){
        if(dep>0&&dep<11) deporte=dep;
        else deporte=-1;}
    void setEquipo(int num){equipo=num;}
    void setMatricula(float p){
        if(p>=0) matricula=p;
        else matricula=-1;}


//------------------------------------------------------
///METODOS*********************************************************************
    bool operator ==(Deporte d);
    void Cargar(int d);
    void Mostrar();
};

void Jugador::Cargar(int d=-1){
        int cl, dep, equi;
        float matri;
        Fecha fechita;

        if(d==-1){
            cout<<"DNI: ";
            cin>>DNI;
            setDNI(DNI);}
            else{
                setDNI(d);
            }

        cout<<"NOMBRE: ";
        cargarCadena(nombre,29);

        cout<<"APELLIDO: ";
        cargarCadena(apellido,29);

        cout<<"EMAIL: ";
        cargarCadena(email,29);

        cout<<"TELEFONO: ";
        cargarCadena(telefono,29);

        cout<<"FECHA DE INSCRIPCION: "<<endl;
        fechita.Cargar();
        setFechaInscripcion(fechita);

        cout<<"CLAUSTRO: ";
        cin>>cl;
        setClaustro(cl);

        cout<<"ID DE DEPORTE: ";
        cin>>dep;
        setDeporte(dep);

        cout<<"NUMERO DE EQUIPO: ";
        cin>>equi;
        setEquipo(equi);

        cout<<"MATRICULA: ";
        cin>>matri;
        setMatricula(matri);

        setEstado(true);
}

void Jugador::Mostrar(){
    if(estado){

            cout<<"DNI: ";
            cout<<DNI<<endl;

            cout<<"Nombre: ";
            cout<<nombre<<endl;
            cout<<"APELLIDO: ";
            cout<<apellido<<endl;
            cout<<"EMAIL: ";
            cout<<email<<endl;
            cout<<"TELEFONO: ";
            cout<<telefono<<endl;
            cout<<"Fecha de inscripcion: "<<endl;
            fechaInscripcion.Mostrar();
            cout<<"CLAUSTRO: ";
            cout<<claustro<<endl;
            cout<<"NUMERO DE DEPORTE:";
            cout<<deporte<<endl;
            cout<<"NUMERO DE EQUIPO: ";
            cout<<equipo<<endl;
            cout<<"MATRICULA: $";
            cout<<matricula;
            cout<<endl<<endl;
        }

}


#endif // CLSJUGADORES_H_INCLUDED
