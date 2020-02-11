#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "NodoCircular.h"
#include <string>
#include <iostream>

using namespace std;

class ListaCircular
{
    private:
        NodoCircular *primero;
        NodoCircular *ultimo;
    public:
        ListaCircular();
        bool estadoLista();
        void insertarNodo();
        void imprimirLista();
        void generarDot();
        void generarImagen();
        ~ListaCircular();
};

#endif