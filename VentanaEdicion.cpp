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
    while(entrada!=27){
        entrada=getch();
        gotoxy(fila,0);
        fila = fila + 1;
        cout<<entrada;
    }
}

VentanaEdicion::~VentanaEdicion(){}