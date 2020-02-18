#ifndef VENTANA_H
#define VENTANA_H

#include "VentanaEdit.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Ventana
{
    private:
        int centroMenu=45;
        int lineaMenu=5;
        int inKeyborad;
        int ancho=GetSystemMetrics(SM_CXSCREEN);
        int alto=GetSystemMetrics(SM_CYSCREEN);
        char caracter;
        string rutaArchivo;
        //VentanaEdit ventanaEdiccion;
        
    public:
        Ventana();
        void gotoxy(int posx,int posy);
        void menu();
        void opMenu(int op);
        ~Ventana();
};


#endif