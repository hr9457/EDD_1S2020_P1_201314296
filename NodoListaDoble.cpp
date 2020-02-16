#include "NodoListaDoble.h"

//contructor
NodoListaDoble::NodoListaDoble(char arg,int posx,int posy){
    this->letra=arg;
    this->posx=posx;
    this->posy=posy;
    siguiente = NULL;
    anterior = NULL;
}

//retorno de valor
char NodoListaDoble::getLetra(){
    return letra;
}

int NodoListaDoble::getPosx(){
    return posx;
}

int NodoListaDoble::getPosy(){
    return posy;
}

//destructor
NodoListaDoble::~NodoListaDoble(){}