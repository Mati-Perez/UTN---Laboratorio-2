#ifndef CLSTIPODEDEPORTE_H_INCLUDED
#define CLSTIPODEDEPORTE_H_INCLUDED

class TipoDeporte{
private:
    int id;
    char nombre[30];
    int nivel;
    bool estado;

public:
    void setId(int i){id=i;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setNivel(int lv){
        if(lv>0&&lv<9){
        nivel=lv;}
        else{
            nivel=-1;
        }}
    void setEstado(bool e){estado=e;}

    int getId(){return id;}
    const char *getNombre(){return nombre;}
    int getNivel(){return nivel;}
    int getEstado(){return estado;}

    void Cargar(int tam);
    void Mostrar();
};

void TipoDeporte::Cargar(int tam=0){
        int lv;
        cout<<"ID : ";
        setId(tam);
        cout<<getId()<<endl;

        cout<<"NOMBRE: ";
        cargarCadena(nombre,29);

        cout<<"NIVEL: ";
        cin>>lv;
        setNivel(lv);

        estado=true;
    }

void TipoDeporte::Mostrar(){
        if(estado){
            cout<<"ID: ";
            cout<<id<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"NIVEL: ";
            cout<<nivel<<endl;
            cout<<endl;
    }
}

#endif // CLSTIPODEDEPORTE_H_INCLUDED
