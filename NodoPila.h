#ifndef NODOPILA_H
#define NODOPILA_H

#include <string>
#include <iostream>
using namespace std;

class NodoPila
{
    private:
        string palabraBuscada;
        string palabraRemplazar;
        bool estado;
        
    public:
        NodoPila *siguiente;
        NodoPila(string arg1);
        void setPalabraBuscada();
        string getPalabraBuscada();
        void setPalabraRemplazar();
        string getPalabraRemplazar();
        void setEstado();
        bool getEstado();
        ~NodoPila();
};

#endif