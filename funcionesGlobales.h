#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED


void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}

///FUNCIONES PARA ARCHIVO JUGADORES****************************************

bool verificarJugador(Jugador jug){

    ///DNI NO DEBE REPETIRSE *****************
    ArchivoJugador archi("Jugadores.dat");
    int pos=archi.buscarDNI(jug.getDNI());
    if(pos>=0){
        cout<<"YA EXISTE ESTE DNI!"<<endl;
        return false;
    }

    ///CLAUSTRO DE 1 A 4 *********************
    if(jug.getClaustro()==-1){
        cout<<"CLAUSTRO INCORRECTO"<<endl;
        return false;
    }

    ///DEPORTE DE 1 A 10 *********************
    if(jug.getDeporte()==-1){
        cout<<"DEPORTE INCORRECTO"<<endl;
        return false;
    }

    ///FECHA VALIDA ********************************
    if(!validarFecha(jug.getFechaInscripcion())){
        cout<<"FECHA INVALIDA"<<endl<<endl;
        return false;
    }
    ///MATRICULA > 0 ********************************
    if(jug.getMatricula()==-1){
        cout<<"MATRICULA INCORRECTA"<<endl;
        return false;
    }


    ///VERIFICAR QUE EXISTA EL ID DE DEPORTE********
    Deporte dep;
    ArchivoDeporte archiDep("deportes.dat");
    bool existeDep=false;
    int cantidadDeporte=archiDep.contarRegistros();

    for(int i=0;i<cantidadDeporte;i++){
        dep=archiDep.leerRegistro(i);
        if(jug.getDeporte()==dep.getId()){
            existeDep=true;
        }

    }
    if(!existeDep){
        cout<<"DEPORTE NO ENCONTRADO"<<endl;
        return false;
    }

    ///VERIFICAR QUE EXISTA EL NUMERO DE EQUIPO
    Equipo eq;
    ArchivoEquipo archiEq("equipos.dat");
    bool existeEq=false;
    int cantEquipos=archiEq.contarRegistros();
    for(int i=0;i<cantEquipos;i++){
        eq=archiEq.leerRegistro(i);
        if(eq.getId()==jug.getEquipo()){
            existeEq=true;
        }
    }

    if(!existeEq) {
        cout<<"EQUIPO NO ENCONTRADO"<<endl;
        return false;
    }

    return true;
}

bool agregarJugador(){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    reg.Cargar();
    if(verificarJugador(reg)){
        bool escribio=archi.agregarRegistro(reg);
        return escribio;
    }
    return false;
}

void listarJugador(){
    int d;
    cout<<"INGRESE DNI DEL JUGADOR: "<<endl;
    cin>>d;
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    int pos=archi.buscarDNI(d);
    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
    } else {cout<<"DNI NO ENCONTRADO!"<<endl;}
    return;
}

void listarJugadores(){
    ArchivoJugador archi("jugadores.dat");
    archi.listarRegistros();
    return;
}

bool modificarFecha(){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    Fecha aux(1,1,1);
    int d;
    cout<<"INGRESE EL DNI DEL JUGADOR AL QUE DESEA CAMBIAR LA FECHA: ";
    cin>>d;
    int pos=archi.buscarDNI(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"INGRESE UNA NUEVA FECHA: "<<endl;
        aux.Cargar();
    } else {
    cout<<"NO SE ENCONTRO JUGADOR CON ESTE DNI"<<endl;
    return false;
    }
    system("cls");
    if(validarFecha(aux)){
        reg.setFechaInscripcion(aux);
        archi.modificarRegistro(pos,reg);
        reg.Mostrar();
        cout<<endl<<endl;
        return true;
    } else{cout<<"FECHA INCORRECTA"<<endl;
    return false;}
}

bool eliminarJugador(){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    int d;
    char opc;
    cout<<"INGRESE EL DNI DEL JUGADOR A BORRAR: ";
    cin>>d;
    int pos=archi.buscarDNI(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        cout<<"JUGADOR: "<<endl;
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA BORRAR EL REGISTRO?(S/N)"<<endl;
        cin>>opc;
        if(opc=='s' ||opc=='S'){
            reg.setEstado(false);
            return(archi.modificarRegistro(pos,reg));

        }
    } else {
        cout<<"NO SE ENCONTRO JUGADOR CON ESTE DNI"<<endl;
        return false;
    }
    return false;
}


///FUNCIONES PARA ARCHIVO DEPORTES ***********************************************

bool verificarDeporte(Deporte dep){


    ///TIPO DE DEPORTE DE 1 A 21 *********************
    if(dep.getTipo()==-1){
        cout<<"TIPO DE DEPORTE INCORRECTO"<<endl;
        return false;
    }

    ///FECHA VALIDA *********************************
    if(dep.getAnioOrigen()<1800 ||dep.getAnioOrigen()>2023){
        cout<<"FECHA INVALIDA"<<endl<<endl;
        return false;
    }

    ///TIPO DE DEPORTE VALIDO ************************
    TipoDeporte tip;
    ArchivoTipoDeporte archiTip("TipodeDeporte.dat");
    bool existeTipo=false;
    int cantTipos=archiTip.contarRegistros();

    for(int i=0;i<cantTipos;i++){
        tip=archiTip.leerRegistro(i);
        if(tip.getId()==dep.getTipo()){
            existeTipo=true;
        }
    }

    if(!existeTipo) {
        cout<<"TIPO DE DEPORTE NO ENCONTRADO"<<endl;
        return false;
    }

    return true;
}

bool agregarDeporte(){

    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int tam=archi.contarRegistros();
    reg.Cargar(tam+1);
    if(verificarDeporte(reg)){
        bool escribio=archi.agregarRegistro(reg);
        return escribio;
    }
    return false;
}

void listarDeporte(){
    int d;
    cout<<"INGRESAR EL ID DEL DEPORTE: "<<endl;
    cin>>d;
    Deporte reg;
    ArchivoDeporte archi("deportes.dat");

    int pos=archi.buscarId(d);
    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
    } else {cout<<"DEPORTE NO ENCONTRADO!"<<endl;}
    return;

}

void listarDeportes(){
    ArchivoDeporte archi("deportes.dat");
    archi.listarRegistros();
    return;
}

bool modificarAnio(){

    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int d, nuevo;
    cout<<"INGRESE EL ID DEL DEPORTE AL QUE DESEE CAMBIAR EL ANIO: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"INGRESE EL NUEVO ANIO: "<<endl;
        cin>>nuevo;
    } else {
    cout<<"NO SE ENCONTRO EL DEPORTE"<<endl;
    return false;
    }
    system("cls");
    if(nuevo>1800){
        reg.setAnioOrigen(nuevo);
        archi.modificarRegistro(pos,reg);
        reg.Mostrar();
        cout<<endl<<endl;
        return true;
    } else{cout<<"ANIO INCORRECTO"<<endl;
    return false;}
}

bool eliminarDeporte(){

    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int d;
    char opc;
    cout<<"INGRESE EL ID DEL DEPORTE POR BORRAR: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        cout<<"DEPORTE: "<<endl;
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA BORRAR EL REGISTRO?(S/N)"<<endl;
        cin>>opc;
        if(opc=='s' ||opc=='S'){
            reg.setEstado(false);
            return(archi.modificarRegistro(pos,reg));

        }
    } else {
        cout<<"NO SE ENCONTRO DEPORTE CON ESTE ID"<<endl;
        return false;
    }
    return false;
}

///FUNCIONES PARA EL ARCHIVO EQUIPOS *************************************

bool verificarEquipo(Equipo eq){
    if(eq.getNivel()==-1){
        cout<<"ERROR CON EL NIVEL DE DIFICULTAD"<<endl<<endl;
        return false;
    }
    return true;

}


bool agregarEquipo(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int tam=archi.contarRegistros();
    reg.Cargar(tam+1);
    if(verificarEquipo(reg)){
        bool escribio=archi.agregarRegistro(reg);
        return escribio;
    }
    return false;
}


void listarEquipo(){
    int d;
    cout<<"INGRESAR EL ID DEL EQUIPO: "<<endl;
    cin>>d;
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");

    int pos=archi.buscarId(d);
    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
    } else {cout<<"EQUIPO NO ENCONTRADO!"<<endl;}
    return;

}


void listarEquipos(){
    ArchivoEquipo archi("equipos.dat");
    archi.listarRegistros();
    return;
}


bool modificarNombre(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int d;
    char nuevo[30];
    cout<<"INGRESE EL ID DEL EQUIPO AL QUE DESEE CAMBIAR EL NOMBRE: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"INGRESE EL NUEVO NOMBRE: "<<endl;
        cargarCadena(nuevo,29);
        system("cls");
        reg.setNombre(nuevo);
        archi.modificarRegistro(pos,reg);
        reg.Mostrar();
        cout<<endl<<endl;
        return true;
    } else {
    cout<<"NO SE ENCONTRO EL EQUIPO"<<endl;
    return false;
    }
}


bool eliminarEquipo(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int d;
    char opc;
    cout<<"INGRESE EL ID DEL EQUIPO POR BORRAR: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        cout<<"EQUIPO: "<<endl;
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA BORRAR EL REGISTRO?(S/N)"<<endl;
        cin>>opc;
        if(opc=='s' ||opc=='S'){
            reg.setEstado(false);
            return(archi.modificarRegistro(pos,reg));

        }
    } else {
        cout<<"NO SE ENCONTRO EQUIPO CON ESTE ID"<<endl;
        return false;
    }
    return false;
}

///FUNCIONES PARA EL ARCHIVO TIPO DE DEPORTES ****************************
bool verificarTipo(TipoDeporte tip){
    if(tip.getNivel()==-1){
        cout<<"ERROR CON EL NIVEL"<<endl<<endl;
        return false;
    }
    return true;
}

bool agregarTipo(){
    TipoDeporte reg;
    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    int tam=archi.contarRegistros();
    reg.Cargar(tam+1);
    if(verificarTipo(reg)){
        bool escribio=archi.agregarRegistro(reg);
        return escribio;
    }
    return false;
}


void listarTipo(){
    int d;
    cout<<"INGRESAR EL ID DEL TIPO DE DEPORTE: "<<endl;
    cin>>d;
    TipoDeporte reg;
    ArchivoTipoDeporte archi("TipodeDeporte.dat");

    int pos=archi.buscarId(d);
    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
    } else {cout<<"TIPO DE DEPORTE NO ENCONTRADO!"<<endl;}
    return;
}


void listarTipos(){
    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    archi.listarRegistros();
    return;
}


bool modificarNivel(){
    TipoDeporte reg;
    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    int d;
    int nuevo;
    cout<<"INGRESE EL ID DEL TIPO DE DEPORTE AL QUE DESEE CAMBIAR EL NIVEL: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"INGRESE EL NUEVO NIVEL: "<<endl;
        cin>>nuevo;
        system("cls");
    } else {
    cout<<"NO SE ENCONTRO EL EQUIPO"<<endl;
    return false;
    }
    reg.setNivel(nuevo);
    archi.modificarRegistro(pos,reg);
    reg.Mostrar();
    cout<<endl<<endl;
    return true;
}


bool eliminarTipo(){
    TipoDeporte reg;
    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    int d;
    char opc;
    cout<<"INGRESE EL ID DEL TIPO DE DEPORTE POR BORRAR: ";
    cin>>d;
    int pos=archi.buscarId(d);

    if(pos>=0){
        reg=archi.leerRegistro(pos);
        cout<<"TIPO DE DEPORTE: "<<endl;
        reg.Mostrar();
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA BORRAR EL REGISTRO?(S/N)"<<endl;
        cin>>opc;
        if(opc=='s' ||opc=='S'){
            reg.setEstado(false);
            return(archi.modificarRegistro(pos,reg));
        }
    } else {
        cout<<"NO SE ENCONTRO TIPO DE DEPORTE CON ESTE ID"<<endl;
        return false;
    }
    return false;
}

///FUNCIONES PARA EL MENU CONFIGURACION **********************************

bool copiaJugadores(){

    ArchivoJugador archi("jugadores.dat");
    Jugador reg;
    int cantReg=archi.contarRegistros();
    int i;
    FILE *p;
    p=fopen("jugadores.bkp", "wb");
    if(p==NULL) return false;
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        fwrite(&reg, sizeof reg,1, p);
    }
    fclose(p);
    ArchivoJugador archiBak("jugadores.bkp");
    archiBak.listarRegistros();
    return true;
}

bool copiaDeportes(){
    ArchivoDeporte archi("deportes.dat");
    Deporte reg;
    int cantReg=archi.contarRegistros();
    int i;
    FILE *p;
    p=fopen("deportes.bkp", "wb");
    if(p==NULL) return false;
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        fwrite(&reg, sizeof reg,1, p);
    }
    fclose(p);
    ArchivoDeporte archiBak("deportes.bkp");
    archiBak.listarRegistros();
    return true;

}

bool copiaEquipos(){

    ArchivoEquipo archi("equipos.dat");
    Equipo reg;
    int cantReg=archi.contarRegistros();
    int i;
    FILE *p;
    p=fopen("equipos.bkp", "wb");
    if(p==nullptr) {
            return false;}
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        fwrite(&reg, sizeof reg,1, p);
    }
    fclose(p);

    ArchivoEquipo archiBak("equipos.bkp");
    archiBak.listarRegistros();
    return true;
}

bool copiaTipos(){

    ArchivoTipoDeporte archi("TipodeDeporte.dat");
    TipoDeporte reg;
    int cantReg=archi.contarRegistros();
    int i;
    FILE *p;
    p=fopen("TipodeDeporte.bkp", "wb");
    if(p==NULL) return false;
    for(i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        fwrite(&reg, sizeof reg,1, p);
    }
    fclose(p);
    ArchivoTipoDeporte archiBak("TipodeDeporte.bkp");
    archiBak.listarRegistros();
    return true;
}

bool restaurarJugadores(){
    Jugador reg;
    FILE *pBak;
    pBak=fopen("jugadores.bkp","rb");
    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("jugadores.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
    return true;
}

bool restaurarDeportes(){
    FILE *pBak;
    pBak=fopen("deportes.bkp","rb");
    Deporte reg;
    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("deportes.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
    return true;
}

bool restaurarEquipos(){
    Equipo reg;
    FILE *pBak;
    pBak=fopen("equipos.bkp","rb");
    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("equipos.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
    return true;
}

bool restaurarTipos(){
    TipoDeporte reg;
    FILE *pBak;
    pBak=fopen("TipodeDeporte.bkp","rb");
    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("TipodeDeporte.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
    return true;
}

bool inicioJugadores(){
    Jugador reg;

    FILE *pBak;
    pBak=fopen("jugadores.ini","rb");
    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("jugadores.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);

    return true;
}

bool inicioDeportes(){
    Deporte reg;
    FILE *pBak;
    pBak=fopen("deportes.ini","rb");

    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("deportes.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);

    return true;

}

bool inicioEquipos(){
    Equipo reg;
    FILE *pBak;
    pBak=fopen("equipos.ini","rb");

    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("equipos.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);

    return true;
}



bool inicioTipoDeporte(){
    TipoDeporte reg;
    FILE *pBak;
    pBak=fopen("TipodeDeporte.ini","rb");

    if(pBak==NULL)return false;

    FILE *p;
    p=fopen("TipodeDeporte.dat","wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&reg, sizeof reg, 1, pBak)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);

    return true;
}

void establecerDatos(){
   if(inicioDeportes()&&inicioJugadores()&&inicioEquipos()&&inicioTipoDeporte()) cout<<"DATOS ESTABLECIDOS EXITOSAMENTE!"<<endl;
        else cout<<"ERROR AL ESTABLECER LOS DATOS INICIALES"<<endl;
}


#endif // FUNCIONESGLOBALES_H_INCLUDED
