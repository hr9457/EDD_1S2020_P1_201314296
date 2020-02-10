#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

#include "NodoListaDoble.h"
#include <iostream>

using namespace std;

class ListaDobleEnlazada
{
    private:
        NodoListaDoble *primero;
        NodoListaDoble *ultimo;

    public:        
        ListaDobleEnlazada();
        bool estadoLista();
        void insertarNodo(char arg);
        void eliminarNodo();
        void imprimirLista();
        void generarGrafico();
        void generarImagen();
        ~ListaDobleEnlazada();
};


#endif