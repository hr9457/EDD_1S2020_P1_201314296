#include "Pila.h"

//constructor
Pila::Pila(){
    cima=NULL;
}

//estado de la pila
bool Pila::estadoPila(){
    if(cima==NULL){
        return true;
    }else{
        return false;
    }
}

//metodo push para insertar elementos en la pila
void Pila::Push(string arg){
    NodoPila *nodoTemporal = new NodoPila(arg);
    if(estadoPila()==true)
    {
        cima=nodoTemporal;
    }
    else
    {
        nodoTemporal->setSiguiente(cima);
        cima=nodoTemporal;
    }
}

//metodo pop para sacar de la pila
void Pila::Pop(){
    if(estadoPila()==true){
        cout<<"No hay elemento en la pila"<<endl;
    }
    else
    {        
    }    
}


//metodo para generar el archivo dot de la pila
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
            "[shape=box,label="<<nodoAuxiliar->getPalabraBuscada()<<"];"<<endl;
            nodoAuxiliar = nodoAuxiliar->getSiguiente();
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

//metodo para genera la imagen del Dot
void Pila::generarImagen()
{
    system("dot.exe -Tpng ArchivosDot\\Pila.dot -o Reportes\\Pila.png");
}

//destructor
Pila::~Pila(){}