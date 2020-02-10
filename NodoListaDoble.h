#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include <iostream>
using namespace std;

class NodoListaDoble
{
    private:
        char letra;
        
    public:
        NodoListaDoble *siguiente;
        NodoListaDoble *anterior;
        NodoListaDoble(char arg);
        char getLetra();
        ~NodoListaDoble();
};

#endif
