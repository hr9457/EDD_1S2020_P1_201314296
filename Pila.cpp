#include "Pila.h"

Pila::Pila(){
    cima=NULL;
}

bool Pila::estadoPila(){
    if(cima==NULL){
        return true;
    }else{
        return false;
    }
}

void Pila::Push(string arg){
    NodoPila *nodoTemporal = new NodoPila(arg);
    if(estadoPila()==NULL)
    {
        cima=nodoTemporal;
    }
    else
    {
        nodoTemporal->siguiente=cima;
        cima=nodoTemporal;
    }
}

void Pila::Pop(){
    if(estadoPila()==NULL){
        cout<<"No hay elemento en la pila"<<endl;
    }
    else
    {
        cima=cima->siguiente;
    }
    
}

void Pila::generarDot(){
    int numeroNodo = 0;
    ofstream archivo("ArchivosDot\\Pila.dot");
    archivo<<"digraph Pila1{"<<endl;
    if(estadoPila()==true){

    }
    else
    {
        NodoPila *nodoAuxiliar = cima;
        while(nodoAuxiliar!=NULL)
        {
            archivo<<"Nodo"<<numeroNodo<<
            "[shape=box,label="<<nodoAuxiliar->getPalabraBuscada()<<
            "];"<<endl;
            nodoAuxiliar = nodoAuxiliar->siguiente;
            numeroNodo = numeroNodo + 1;
        }
        //union de los nodos
        for (int i = 0; i < numeroNodo-1; i++)
        {
            archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
        }
        archivo<<"label = \" Pila \" "<<endl;
        archivo<<"}"<<endl;
        archivo.close();        
    }

}

void Pila::generarImagen()
{
    system("dot.exe -Tpng ArchivosDot\\Pila.dot -o Reportes\\Pila.png");
}

Pila::~Pila(){}