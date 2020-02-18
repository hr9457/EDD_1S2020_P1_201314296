#ifndef VENTANAEDIT_H
#define VENTANNAEDIT_H

#include "ListaDobleEnlazada.h"
#include "NodoListaDoble.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

class VentanaEdit
{
    private:
        int inKeyboard,columna=1,saltoLinea=1,finalPantalla=117,altoPantalla=27;
        int inicioMenu=1;
        int columnaBuscar=inicioMenu, altoPantallaBuscar=altoPantalla;
        int ancho=GetSystemMetrics(SM_CXSCREEN);
        int alto=GetSystemMetrics(SM_CYSCREEN);
        char caracter;
        ListaDobleEnlazada listaDoble;//creacion objeto para la lista doble 
        string palabraBuscar,palabraRemplazar,rutaArchivo;
        string rutaDeApertura;
        char caracterArchivo;
        
    public:
        VentanaEdit();
        VentanaEdit(string ruta);
        void lercuturaArchivo(string arg);
        void gotoxy(int posx,int posy);
        void ediccion();
        void marco();
        void Repintar();
        void guardar(string ruta);
        ~VentanaEdit();
};


#endif