#ifndef CLSDEPORTES_H_INCLUDED
#define CLSDEPORTES_H_INCLUDED


class Deporte{
private:
    int id;
    char nombre[30];
    int tipo;
    int anioOrigen;
    bool estado;

public:

    ///SETS******************************************
    void setId(int i){id=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(int t){
        if(t>0&&t<22){
        tipo=t;}
        else{
            tipo=-1;
        }}
    void setAnioOrigen(int a){
        if(a>=1800){
        anioOrigen=a;}
        else{anioOrigen=-1;}}
    void setEstado(bool e){estado=e;}

    ///GETS****************************************
    int getId(){return id;}
    const char *getNombre(){return nombre;}
    int getTipo(){return tipo;}
    int getAnioOrigen(){return anioOrigen;}
    int getEstado(){return estado;}

    ///METODOS ************************************
    void Cargar(int tam);

    void Mostrar();
};



void Deporte::Cargar(int tam=0){
        int t;
        int fechita;

        cout<<"ID : ";
        setId(tam);
        cout<<getId()<<endl;

        cout<<"NOMBRE: ";
        cargarCadena(nombre,29);

        cout<<"TIPO: ";
        cin>>t;
        setTipo(t);

        cout<<"ANIO DE ORIGEN: ";
        cin>>fechita;
        setAnioOrigen(fechita);

        estado=true;

}

void Deporte::Mostrar(){
        if(estado){
            cout<<"ID: ";
            cout<<id<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"TIPO: ";
            cout<<tipo<<endl;
            cout<<"ANIO DE ORIGEN: ";
            cout<<anioOrigen<<endl;
            cout<<endl;
    }
}

#endif // CLSDEPORTES_H_INCLUDED
