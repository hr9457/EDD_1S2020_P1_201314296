#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H

#include "NodoListaDoble.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>//archivos

using namespace std;

class ListaDobleEnlazada
{
    private:
        NodoListaDoble *primero;
        NodoListaDoble *ultimo;

    public:        
        ListaDobleEnlazada();
        bool estadoLista();
        void insertarNodo(char arg,int posx,int posy);
        void eliminarNodo();
        void imprimirLista();
        void buscarPalabra(string palabra1);
        void generarDot();
        void generarImagen();
        ~ListaDobleEnlazada();
};


#endif