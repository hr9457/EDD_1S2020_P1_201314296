#include "NodoPila.h"

//constructor
NodoPila::NodoPila(string arg1){
    this->siguiente=NULL;
    this->palabraBuscada=arg1;
}

//metodo set y get para el puntero siguiente
NodoPila* NodoPila::getSiguiente(){
    return siguiente;
}

void NodoPila::setSiguiente(NodoPila *puntero)
{
    siguiente=puntero;
}

//para lo que almacenara el nodo
string NodoPila::getPalabraBuscada(){
    return palabraBuscada;
}

void NodoPila::setPalabraBuscada(string arg)
{
    palabraBuscada=arg;
}

string NodoPila::getPalabraRemplazar()
{
    return palabraRemplazar;
}

void NodoPila::setPalabraRemplazar(string arg)
{  
    palabraRemplazar=arg;
}

//destructor
NodoPila::~NodoPila(){}