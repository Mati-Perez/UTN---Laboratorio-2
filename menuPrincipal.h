#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menu(){
    int opc;
    while(true){
    system("cls");
    cout<<"\t\t*****MENU PRINCIPAL*****"<<endl;
    cout<<"****************************************************************"<<endl;

    cout<<"1) MENU JUGADORES"<<endl;
    cout<<"2) MENU DEPORTES"<<endl;
    cout<<"3) MENU EQUIPOS"<<endl;
    cout<<"4) MENU TIPOS DE DEPORTE"<<endl;
    cout<<"5) REPORTES"<<endl;
    cout<<"6) CONFIGURACION"<<endl;
    cout<<"****************************************************************"<<endl;
    cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;
    cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");
    switch(opc){
    case 1:
        menuJugadores();
        break;
    case 2:
        menuDeportes();
        break;
    case 3:
        menuEquipos();
        break;
    case 4:
        menuTipoDeportes();
        break;
    case 5:
        reportes();
        break;
    case 6:
        menuConfiguracion();
        break;
    case 0:
        return;
        break;
    default:
        cout<<"OPCION INCORRECTA"<<endl;
        break;

    }
    system("pause");

    }
    return;

}


#endif // MENUPRINCIPAL_H_INCLUDED
