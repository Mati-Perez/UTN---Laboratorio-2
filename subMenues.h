#ifndef SUBMENUES_H_INCLUDED
#define SUBMENUES_H_INCLUDED

///JUGADORES **************************************************************
void menuJugadores(){
    int opc;
    while(true){
    system("cls");
    cout<<"\t\tMENU JUGADORES"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"1) AGREGAR JUGADOR"<<endl;
    cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
    cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
    cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
    cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"***********************"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    system("cls");
    switch(opc){
    case 1:
        if(agregarJugador()){
            cout<<"Registro cargado exitosamente!"<<endl;

        } else{
        cout<<"no se pudo cargar el registro"<<endl;
        };
        break;
    case 2:
        listarJugador();
        break;
    case 3:
        listarJugadores();
        break;
    case 4:
        if(modificarFecha()) cout<<"Fecha cambiada exitosamente!"<<endl;
        else cout<<"Error al modificar la fecha"<<endl;
        break;
    case 5:
        if(eliminarJugador()) cout<<"Registro borrado exitosamente"<<endl;
        else cout<<"Error al borrar el registro"<<endl;
        break;
    case 0:
        return;
    default:
        cout<<"OPCION INCORRECTA"<<endl;
        break;


    }
    system("pause");

    }
    return;

}

///DEPORTES ***************************************************************

void menuDeportes(){
    int opc;
    while(true){
    system("cls");
    cout<<"\t\tMENU DEPORTES"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"1) AGREGAR DEPORTE"<<endl;
    cout<<"2) LISTAR DEPORTE POR ID"<<endl;
    cout<<"3) LISTAR TODO"<<endl;
    cout<<"4) MODIFICAR AÑO DE ORIGEN"<<endl;
    cout<<"5) ELIMINAR REGISTRO"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    system("cls");
    switch(opc){
    case 1:
        if(agregarDeporte()) cout<<"Registro cargado exitosamente!"<<endl;
        else cout<<"no se pudo cargar el registro"<<endl;
        break;
    case 2:
        listarDeporte();
        break;
    case 3:
        listarDeportes();
        break;
    case 4:
        if(modificarAnio()) cout<<"Fecha cambiada exitosamente!"<<endl;
            else cout<<"Error al cambiar la fecha"<<endl;
        break;
    case 5:
        if(eliminarDeporte()) cout<<"Registro borrado exitosamente"<<endl;
        else cout<<"Error al borrar el registro"<<endl;
        break;
    case 0:
        return;
    default:
        cout<<"OPCION INCORRECTA"<<endl;
        break;


    }
    system("pause");

    }
    return;

}

///EQUIPOS ****************************************************************

void menuEquipos(){
    int opc;
    while(true){
        system("cls");
        cout<<"\t\tMENU EQUIPOS"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(agregarEquipo()) cout<<"Registro cargado exitosamente"<<endl;
                else cout<<"no se pudo cargar el registro"<<endl;
                break;
            case 2:
                listarEquipo();
                break;
            case 3:
                listarEquipos();
                break;
            case 4:
                if(modificarNombre()) cout<<"Nombre cambiado exitosamente!"<<endl;
                else cout<<"Error al modificar el nombre"<<endl;
                break;
            case 5:
                if(eliminarEquipo()) cout<<"Registro borrado exitosamente"<<endl;
                else cout<<"Error al borrar el registro"<<endl;
                break;
            case 0:
                return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");

    }
    return;
}

///TIPO DE DEPORTES *******************************************************
void menuTipoDeportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"\t\tMENU TIPOS DE DEPORTE"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"1) AGREGAR TIPO"<<endl;
        cout<<"2) LISTAR TIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(agregarTipo()) cout<<"Registro cargado exitosamente"<<endl;
                else cout<<"Error al cargar el registro"<<endl;
                break;
            case 2:
                listarTipo();
                break;
            case 3:
                listarTipos();
                break;
            case 4:
                if(modificarNivel()) cout<<"Nivel cambiado exitosamente"<<endl;
                else cout<<"Error al cambiar el nivel"<<endl;
                break;
            case 5:
                if(eliminarTipo()) cout<<"Registro borrado exitosamente!"<<endl;
                else cout<<"Error al borrar el registro"<<endl;
                break;
            case 0:
                return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");

    }
    return;
}

///CONFIGURACION **********************************************
void menuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout<<"\t\tMENU CONFIGURACION"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"9) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                if(copiaJugadores()) cout<<"COPIA EXITOSA!"<<endl;
                else cout<<"ERROR AL CREAR LA COPIA DE SEGURIDAD"<<endl;
                cout<<endl;
                break;
            case 2:
                if(copiaDeportes()) cout<<"COPIA EXITOSA!"<<endl;
                else cout<<"ERROR AL CREAR LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 3:
                if(copiaEquipos()) cout<<"COPIA EXITOSA!"<<endl;
                else cout<<"ERROR AL CREAR LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 4:
                if(copiaTipos()) cout<<"COPIA EXITOSA!"<<endl;
                else cout<<"ERROR AL CREAR LA COPIA DE SEGURIDAD"<<endl;
                break;
            case 5:
                if(restaurarJugadores()) cout<<"RESTAURACION EXITOSA!"<<endl;
                else cout<<"ERROR CON LA RESTAURACION"<<endl;
                break;
            case 6:
                if(restaurarDeportes()) cout<<"RESTAURACION EXITOSA!"<<endl;
                else cout<<"ERROR CON LA RESTAURACION"<<endl;
                break;
            case 7:
                if(restaurarEquipos()) cout<<"RESTAURACION EXITOSA!"<<endl;
                else cout<<"ERROR CON LA RESTAURACION"<<endl;
                break;
            case 8:
                if(restaurarTipos()) cout<<"RESTAURACION EXITOSA!"<<endl;
                else cout<<"ERROR CON LA RESTAURACION"<<endl;
                break;
            case 9:
                establecerDatos();
                break;
            case 0:
                return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");

    }
    return;

}


///REPORTES ***************************************************
void reportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"\t\tMENU REPORTES"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"1) PUNTO 1"<<endl;
        cout<<"2) PUNTO 2"<<endl;
        cout<<"3) PUNTO 3"<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 0:
                return;
            default:
                cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
    system("pause");
    }
    return;
}

#endif // SUBMENUES_H_INCLUDED
