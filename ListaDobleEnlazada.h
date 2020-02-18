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
        NodoListaDoble * getPrimero();
        NodoListaDoble * getUltimo();
        bool estadoLista();
        void insertarNodo(char arg,int posx,int posy);
        void eliminarNodo();
        void imprimirLista();
        void insertarNodoEnMedio();
        void buscarPalabra(string palabra1, string palabra2);        
        void generarDot();
        void generarImagen();
        ~ListaDobleEnlazada();
};


#endif