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
        void setLetra(char arg);
        int getPosx();
        void setPosx(int numero);
        int getPosy();
        void setPosy(int numero);
        ~NodoListaDoble();
};

#endif
