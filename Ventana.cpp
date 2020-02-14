#include "Ventana.h"

//funcion gotoxy para pintado de la interface grafica
void Ventana::gotoxy(int posx,int posy)
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = posx;  
    dwPos.Y= posy;  
    SetConsoleCursorPosition(hcon,dwPos); 
}

//constructor
Ventana::Ventana()
{
    CreacionMarco();   
}


//pintado del marco de la ventan
void Ventana::CreacionMarco(){
    for (int i = 0; i <=largoVentana; i++)
    {
        gotoxy(i,0);
        cout<<"*";
        gotoxy(i,24);
        cout<<"*";
        if(i<=24){
            gotoxy(1,i);
            cout<<"*";
            gotoxy(largoVentana,i);
            cout<<"*";
        }
    }
    menu();
}

void Ventana::menu(){
    gotoxy(centorMenus,5);
    cout<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA";
    gotoxy(centorMenus,6);
    cout<<"FACULTAD DE INGENIERIA";
    gotoxy(centorMenus,7);
    cout<<"ESTRUCTURAS DE DATOS";
    gotoxy(centorMenus,8);
    cout<<"PRACTICA 1";
    gotoxy(centorMenus,9);
    cout<<"HECTOR JOSUE OROZCO SALAZAR";
    gotoxy(centorMenus,10);
    cout<<"201314296";
    gotoxy(centorMenus,12);
    cout<<"MENU";
    gotoxy(centorMenus,13);
    cout<<"1. CREAR ARCHIVO";
    gotoxy(centorMenus,14);
    cout<<"2. ABRIR ARCHIVO";
    gotoxy(centorMenus,15);
    cout<<"3. ARCHIVOS RECIENTE";
    gotoxy(centorMenus,16);
    cout<<"4. SALIR";
    gotoxy(centorMenus,18);
    cout<<"INGRESE UNA OPCION DEL MENU: ";
    opMenu=getch();
    selecionMenu(opMenu);
}

//ingreso de la opcion del menu
void Ventana::selecionMenu(int opMenu){
    if(opMenu=1){
        system("cls");
        VentanaEdicion edit;
        system("cls");
        //CreacionMarco();
    }else if(opMenu=4){
        system("exit");
    }
}


//destructor
Ventana::~Ventana(){}