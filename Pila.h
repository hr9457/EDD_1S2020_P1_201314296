#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

#include <iostream>
#include <string>
#include <fstream>
#include <windowsx.h>

using namespace std;

class Pila
{
    private:
        NodoPila *cima;

    public:
        Pila();
        bool estadoPila();
        void Push(string arg);
        void Pop();
        void generarDot();
        void generarImagen();
        ~Pila();
};

#endif