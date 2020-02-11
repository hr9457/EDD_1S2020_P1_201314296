#include "ListaCircular.h"

//contructor
ListaCircular::ListaCircular(){
    primero=NULL;
    ultimo=NULL;
}

//estado de la lista
bool ListaCircular::estadoLista(){
    if(primero==NULL && ultimo==NULL){
        return true;
    }else{
        return false;
    }
}

//metodo insertar nodo
void ListaCircular::insertarNodo(string arg1,string arg2){
    if(estadoLista()==true){
        NodoCircular *nodoTemporal = new NodoCircular(arg1,arg2);
        primero=nodoTemporal;
        ultimo=nodoTemporal;
        ultimo->siguiente=primero;
    }else{
        NodoCircular *nodoTemporal = new NodoCircular(arg1,arg2);
        ultimo->siguiente=nodoTemporal;
        ultimo=nodoTemporal;
        ultimo->siguiente=primero;
    }
}

//metodo para imprimir lista
void ListaCircular::imprimirLista(){
    if(estadoLista()==true){
        cout<<"Lista vacia";
    }else{
        NodoCircular *nodoAuxiliar = primero;
        while (nodoAuxiliar!=NULL){
            cout<<"<--"<<nodoAuxiliar->getNombre()<<"-->"<<endl;
            cout<<"<--"<<nodoAuxiliar->getRuta()<<"-->"<<endl;
            nodoAuxiliar=nodoAuxiliar->siguiente;
        }
        getch();        
    }
}

//metodo para genera archivo Dot
void ListaCircular::generarDot(){
    int numeroNodo = 0;
    ofstream archivo("ArchivosDot\\ListaCircular.dot");
    archivo<<"digraph ListaDoble {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    //para colocar los nodos
    archivo<<"label = \" Lista Circular Simple\" "<<endl;
    archivo<<"}"<<endl;
    archivo<<""<<endl;
    archivo.close();
}

//metodo para generar imagen
void ListaCircular::generarImagen(){
    system("dot.exe -Tpng ArchivosDot\\ListaCircular.dot -o Reportes\\ListaCircular.png");
}

//destructor
ListaCircular::~ListaCircular(){}