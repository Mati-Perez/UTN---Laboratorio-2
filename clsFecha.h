#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED



class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(){
        time_t tiempo=time(nullptr);
        tm* fecha = localtime(&tiempo);
        setDia(fecha->tm_mday);
        setMes(fecha->tm_mon+1);
        setAnio(fecha->tm_year+1900);
    }

    Fecha(int d, int m, int a){
        setDia(d);
        setMes(m);
        setAnio(a);

    }

    void Cargar();
    void Mostrar();

    ///SETTERS
    void setDia(int x){if(x>0 && x<32) dia=x;
    else dia=-1;}
    void setMes(int x){if(x>0 &&x<13) mes=x;
    else dia=-1;}
    void setAnio(int x){if(x>0) anio=x;
    else anio=-1;}
    //gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}



};

void Fecha::Cargar(){
    int d, m, a;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>m;
    setMes(m);
    cout<<"ANIO: ";
    cin>>a;
    setAnio(a);


}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;


}

bool validarFecha(Fecha f){
    Fecha aux;
    ///VALIDAR QUE LA FECHA NO SUPERE LA FECHA ACTUAL---------------------
    if(f.getAnio()>aux.getAnio()){
        return false;
    } else if (f.getAnio()==aux.getAnio() && f.getMes()>aux.getMes()) {
            return false;}
            else if(f.getAnio()==aux.getAnio() && f.getMes()==aux.getMes() && f.getDia()>aux.getDia()){
                return false;
            }
    ///-------------------------------------------------------------------
    ///VALIDAR QUE TENGA 30 O 31 DIAS SEGUN CORRESPONDA
    if(f.getMes()<8){
        if(f.getMes()%2==0){
            if(f.getDia()==31){
                return false;
            }
        }
    }else{
        if(f.getMes()%2!=0){
            if(f.getDia()==31){
                return false;
            }
        }
    }
    ///---------------------------------------------------

    ///VALIDAR EN FEBRERO---------------------------------
    if(f.getMes()==2){
        if((f.getAnio()%4==0) || (f.getAnio()%100!=0 && f.getAnio()%400==0)){
            if(f.getDia()>=30){
                return false;
            }
        } else {
            if(f.getDia()>=29){
                return false;
            }
        }
    }
    ///---------------------------------------------------------------------



    if(f.getDia()!=-1 && f.getMes()!= -1 && f.getAnio()!=-1) return true;
        else return false;
}

#endif // CLSFECHA_H_INCLUDED
