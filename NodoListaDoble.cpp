#include "NodoListaDoble.h"

//contructor
NodoListaDoble::NodoListaDoble(char arg){
    this->letra=arg;
    siguiente = NULL;
    anterior = NULL;
}

//retorno de valor
char NodoListaDoble::getLetra(){
    return letra;
}

//destructor
NodoListaDoble::~NodoListaDoble(){}