#ifndef VENTANAEDIT_H
#define VENTANNAEDIT_H

#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class VentanaEdit
{
    private:
        int inKeyboard,columna=1,saltoLinea=1,finalPantalla=117,altoPantalla=27;
        int ancho=GetSystemMetrics(SM_CXSCREEN);
        int alto=GetSystemMetrics(SM_CYSCREEN);
        char caracter;
        
    public:
        VentanaEdit();
        void gotoxy(int posx,int posy);
        void ediccion();
        void marco();
        ~VentanaEdit();
};


#endif