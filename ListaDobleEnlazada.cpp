#include "ListaDobleEnlazada.h"

//constructor
ListaDobleEnlazada::ListaDobleEnlazada()
{
    primero=NULL;
    ultimo=NULL;
}

//estado de la lista
bool ListaDobleEnlazada::estadoLista(){
    if(primero==NULL && ultimo==NULL){
        return true;
    }else{
        return false;
    }
}

//insertar al final de la lista
void ListaDobleEnlazada::insertarNodo(char arg){
    //nodo temporal para guardar la informacion
    NodoListaDoble *nodoTemporal = new NodoListaDoble(arg);
    if(estadoLista()==true){
        primero = nodoTemporal;
        ultimo = nodoTemporal;
    }else{
        ultimo->siguiente=nodoTemporal;
        nodoTemporal->anterior=ultimo;
        ultimo=nodoTemporal;
    }
}

//eliminar nodo al final
void ListaDobleEnlazada::eliminarNodo(){
    if(estadoLista()==true){
        cout<<"LISTA VACIA"<<endl;
    }else if(primero==ultimo){
        primero=NULL;
        ultimo=NULL;
    }else{
        NodoListaDoble *nodoAuxiliar = ultimo->anterior;
        ultimo->anterior=NULL;
        nodoAuxiliar->siguiente=NULL;
        ultimo=nodoAuxiliar;
    }
}

//impresion de la lista (pruebas)
void ListaDobleEnlazada::imprimirLista(){}

//metodo para generar el grafo - Graphviz
void ListaDobleEnlazada::generarGrafico(){}

//metodo para generar imagen del grafo
void ListaDobleEnlazada::generarGrafico(){}

//destructor
ListaDobleEnlazada::~ListaDobleEnlazada()
{
}