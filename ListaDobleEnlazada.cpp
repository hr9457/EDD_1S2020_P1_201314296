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
void ListaDobleEnlazada::imprimirLista(){
    if(estadoLista()==true){
        cout<<"NO HAY ELEMENTOS EN LA LISTA"<<endl;
        getch();
    }else{
        NodoListaDoble *nodoTemporal = primero;
        while(nodoTemporal!=NULL){
            cout<<"<-- "<<nodoTemporal->getLetra()<<" -->"<<endl;
            nodoTemporal = nodoTemporal->siguiente;
        }
        getch();
    }
}

//metodo para generar el grafo - Graphviz
void ListaDobleEnlazada::generarDot(){
    int numeroNodo = 0;
    ofstream archivo("ArchivosDot\\ListaDobleEnlazada.dot");//escribir un archivo
    archivo<<"digraph ListaDobleEnlazada {"<<endl;
    //para colocar los nodos
    if(estadoLista()==true){        
    }else{        
        NodoListaDoble *nodoTemporal = primero;
        while(nodoTemporal!=NULL){
            archivo<<"Nodo"<<numeroNodo<<"[shape=box,label="<<
            nodoTemporal->getLetra()<<"];"<<endl;
            nodoTemporal = nodoTemporal->siguiente;
            numeroNodo = numeroNodo + 1;
        }
    }
    //union de los nodos
    for (int i = 0; i < numeroNodo-1; i++)
    {
        archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
        archivo<<"Nodo"<<i+1<<"->Nodo"<<i<<";"<<endl;
    }    
    archivo<<"label = \" Lista doblemente enlazada\" "<<endl;
    archivo<<"}"<<endl;
    archivo<<""<<endl;
    archivo.close();
}

//metodo para generar imagen del grafo
void ListaDobleEnlazada::generarImagen(){
    system("dot.exe -Tpng ArchivosDot\\ListaDobleEnlazada.dot -o Reportes\\ListaDobleEnlzada.png");
}

//destructor
ListaDobleEnlazada::~ListaDobleEnlazada(){}