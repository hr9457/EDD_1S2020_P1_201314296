#ifndef NODOPILA_H
#define NODOPILA_H

#include <string>
#include <iostream>
using namespace std;

class NodoPila
{
    private:
        NodoPila *siguiente;
        string palabraBuscada;
        string palabraRemplazar;
        bool estado;
        
    public:
        NodoPila(string arg1);
        
        NodoPila * getSiguiente();
        void setSiguiente(NodoPila *puntero);

        void setPalabraBuscada(string arg);
        string getPalabraBuscada();

        void setPalabraRemplazar(string arg);
        string getPalabraRemplazar();

        ~NodoPila();
};

#endif