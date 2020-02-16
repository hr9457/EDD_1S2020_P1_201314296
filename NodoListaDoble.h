#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include <iostream>
using namespace std;

class NodoListaDoble
{
    private:
        char letra;
        int posx,posy;
        
    public:
        NodoListaDoble *siguiente;
        NodoListaDoble *anterior;
        NodoListaDoble(char arg,int posx,int posy);
        char getLetra();
        int getPosx();
        int getPosy();
        ~NodoListaDoble();
};

#endif
