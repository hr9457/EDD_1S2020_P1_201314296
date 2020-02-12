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
    if(estadoLista()==true){//si el primero nodo a insertar
        NodoCircular *nodoTemporal = new NodoCircular(arg1,arg2);
        primero=nodoTemporal;
        ultimo=nodoTemporal;
        ultimo->siguiente=primero;
    }else{
        NodoCircular *nodoTemporal = new NodoCircular(arg1,arg2);
        ultimo->siguiente=nodoTemporal;
        nodoTemporal->siguiente=primero;
        ultimo=nodoTemporal;
    }
}

//metodo para imprimir lista
void ListaCircular::imprimirLista(){
    if(estadoLista()==true){
        cout<<"Lista vacia";
    }else{
        NodoCircular *nodoAuxiliar = primero;
        do{            
            cout<<"<--"<<nodoAuxiliar->getNombre()<<"-->"<<endl;
            nodoAuxiliar=nodoAuxiliar->siguiente;
        } while (nodoAuxiliar!=primero);
        getch();//espera a una entrda en consola 
    }
}

//metodo para genera archivo Dot
void ListaCircular::generarDot(){
    int numeroNodo = 0;//para colocacion de un indice a los nodos en .dot
    ofstream archivo("ArchivosDot\\ListaCircular.dot");//apertura de archivo
    archivo<<"digraph ListaDoble {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    //para colocar los nodos
    if(estadoLista()==true){        
    }else{
        NodoCircular *nodoTemporal = primero;
        do{            
            archivo<<"Nodo"<<numeroNodo<<"[shape=record,label=\"{<pre>|"<<
            nodoTemporal->getNombre()<<"|<next>}\"];"<<endl;
            nodoTemporal=nodoTemporal->siguiente;
            numeroNodo=numeroNodo+1;
        } while (nodoTemporal!=primero);
    }
    //anidacion de los nodos
    for (int i = 0; i < numeroNodo-1; i++){
        archivo<<"Nodo"<<i<<":next->Nodo"<<i+1<<":pre;"<<endl;
    }
    archivo<<"Nodo"<<numeroNodo-1<<":next->Nodo0:pre;"<<endl;
    archivo<<"label = \" Lista Circular Simple\";"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
}

//metodo para generar imagen
void ListaCircular::generarImagen(){
    system("dot.exe -Tpng ArchivosDot\\ListaCircular.dot -o Reportes\\ListaCircular.png");
}

//destructor
ListaCircular::~ListaCircular(){}