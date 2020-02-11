#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "NodoCircular.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class ListaCircular
{
    private:
        NodoCircular *primero;
        NodoCircular *ultimo;
    public:
        ListaCircular();
        bool estadoLista();
        void insertarNodo(string arg1,string arg2);
        void imprimirLista();
        void generarDot();
        void generarImagen();
        ~ListaCircular();
};

#endif