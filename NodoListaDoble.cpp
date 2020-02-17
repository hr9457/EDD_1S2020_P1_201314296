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

void NodoListaDoble::setLetra(char arg){
    letra=arg;
}



int NodoListaDoble::getPosx(){
    return posx;
}

void NodoListaDoble::setPosx(int numero)
{
    posx=numero;
}



int NodoListaDoble::getPosy(){
    return posy;
}

void NodoListaDoble::setPosy(int numero)
{
    posy=numero;
}

//destructor
NodoListaDoble::~NodoListaDoble(){}