#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

#include <iostream>
#include <string>

using namespace std;

class NodoCircular
{
    private:        
        string NombreArchivo;
        string ruta;

    public:
        NodoCircular *siguiente;
        NodoCircular *anterior;
        NodoCircular(string arg1,string arg2);
        ~NodoCircular();
};

#endif