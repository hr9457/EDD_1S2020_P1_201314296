#include "NodoCircular.h"

//contructor
NodoCircular::NodoCircular(string arg1,string arg2){
    this->NombreArchivo=arg1;
    this->ruta=arg2;
    siguiente=NULL;
}

string NodoCircular::getNombre(){
    return NombreArchivo;
}

string NodoCircular::getRuta(){
    return ruta;
}

//descturctor
NodoCircular::~NodoCircular(){}