#include "VentanaEdicion.h"

void VentanaEdicion::gotoxy(int posx,int posy)
{
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = posx;  
    dwPos.Y= posy;  
    SetConsoleCursorPosition(hcon,dwPos); 
}

VentanaEdicion::VentanaEdicion(){
    escrituraPantalla();
}

void VentanaEdicion::escrituraPantalla(){
    while(caracter!='27'){
        cin>>caracter;
        gotoxy(fila,0);
        cout<<caracter;
        getch();
    }
}

VentanaEdicion::~VentanaEdicion(){}