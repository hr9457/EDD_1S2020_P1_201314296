#ifndef VENTANAEDICION_H
#define VENTANAEDICION_H

#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


class VentanaEdicion
{
    private:
        char caracter;
        int fila=0,columna=0;

        
    public:
        void gotoxy(int posx,int posy);
        VentanaEdicion();
        void escrituraPantalla();
        ~VentanaEdicion();
};


#endif