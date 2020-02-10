#include "iostream"
#include "ListaDobleEnlazada.h"
#include <conio.h>

int main(){
    ListaDobleEnlazada list;
    list.insertarNodo('h');
    list.insertarNodo('e');
    list.insertarNodo('c');
    list.insertarNodo('t');
    list.insertarNodo('o');
    list.insertarNodo('r');
    list.imprimirLista();
    list.generarDot();
    list.generarImagen();
    return 0;
}