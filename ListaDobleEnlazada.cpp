#include "ListaDobleEnlazada.h"



//---------------------constructor
ListaDobleEnlazada::ListaDobleEnlazada()
{
    primero=NULL;
    ultimo=NULL;
}



//-------------------estado de la lista
bool ListaDobleEnlazada::estadoLista(){
    if(primero==NULL && ultimo==NULL){
        return true;
    }else{
        return false;
    }
}



//-------------------insertar al final de la lista
void ListaDobleEnlazada::insertarNodo(char arg,int posx,int posy){
    //nodo temporal para guardar la informacion
    NodoListaDoble *nodoTemporal = new NodoListaDoble(arg,posx,posy);
    if(estadoLista()==true){
        primero = nodoTemporal;
        ultimo = nodoTemporal;
    }else{
        ultimo->siguiente=nodoTemporal;
        nodoTemporal->anterior=ultimo;
        ultimo=nodoTemporal;
    }
}



//--------------------eliminar nodo al final
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



//-----------------------impresion de la lista (pruebas)
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



//------------------Metodo para buscar palabras dentro de la lista
void ListaDobleEnlazada::buscarPalabra(string palabra1, string palabra2){
    if(estadoLista()==true){
        //lista esta vacia
    }else{
        NodoListaDoble *nodoTemporal=primero;//emepezar a recorrer la lista
        string palabraEnLista;//para concatenera los caracteres
        while (nodoTemporal!=NULL)//hasta llegar el ultimo elemento de la lista
        {
            if(nodoTemporal->getLetra()!=' '){//si no es un espacio en blanco

                palabraEnLista = palabraEnLista + nodoTemporal->getLetra();//concatena
                nodoTemporal = nodoTemporal->siguiente;//pasa a siguiente

            }else{

                if(palabra1==palabraEnLista){//revisa si la palabra es la que pasamos

                    //cout<<"palabra Encontrada"<<endl;//salida 
                    //cout<<palabra1.size()<<endl;

                    //posicion en la lista donde se enentra el espacio en blanco
                    NodoListaDoble *espacioBlanco = nodoTemporal;

                    //regreso a la primero letra de la palabra
                    for(int i=0;i<palabra1.size();i++){
                        nodoTemporal = nodoTemporal->anterior;
                    }

                    //cout<<"letra inicio: "<<nodoTemporal->getLetra()<<endl;

                    //remplazo de caracteres en la lista
                    int inicioPalabra2 = 0;

                    do{
                        //si encuentra el espacio en blando en la lista
                        if(nodoTemporal->siguiente != espacioBlanco){
                            //cout<<"dato: "<<nodoTemporal->getLetra()<<endl;
                            //getch();
                            nodoTemporal->setLetra(palabra2[inicioPalabra2]);
                            inicioPalabra2++;
                            nodoTemporal=nodoTemporal->siguiente;
                        }else{
                            
                            //cout<<"dato: "<<nodoTemporal->getLetra()<<endl;
                            //getch();
                            nodoTemporal->setLetra(palabra2[inicioPalabra2]);
                            int posicionX = nodoTemporal->getPosx();
                            int posicionY = nodoTemporal->getPosy();
                            NodoListaDoble *agregar = new NodoListaDoble(palabra2[inicioPalabra2+1],posicionX+1,posicionY);
                            nodoTemporal->siguiente=agregar;
                            agregar->anterior=nodoTemporal;
                            agregar->siguiente=espacioBlanco;
                            espacioBlanco->anterior=agregar;
                            inicioPalabra2++;
                            nodoTemporal=nodoTemporal->siguiente;

                        }                       
                    }while(inicioPalabra2<palabra2.size()-1);

                    break;//encuentro palabra rompo proceso


                }else{//sino
                    //cout<<"palabra no encontrada"<<endl;
                    palabraEnLista="";//vacia lo que tenias concatenado
                    nodoTemporal = nodoTemporal->siguiente;//pasa a siguiente
                }//fin else
            }//fin else            
        }//fin de la lista
        
    }//si la lista vacia esta con datos busca
}//fin del metodo




//----------------metodo para generar el grafo - Graphviz
void ListaDobleEnlazada::generarDot(){
    int numeroNodo = 0;
    ofstream archivo("ArchivosDot\\ListaDobleEnlazada.dot");//escribir un archivo
    archivo<<"digraph ListaDobleEnlazada {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    //para colocar los nodos
    if(estadoLista()==true){        
    }else{        
        NodoListaDoble *nodoTemporal = primero;
        while(nodoTemporal!=NULL){
            archivo<<"Nodo"<<numeroNodo<<"[shape=box,label=\""<<
            nodoTemporal->getLetra()<<"\"];"<<endl;
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






//----------------------metodo para generar imagen del grafo
void ListaDobleEnlazada::generarImagen(){
    system("dot.exe -Tpng ArchivosDot\\ListaDobleEnlazada.dot -o Reportes\\ListaDobleEnlzada.png");
}




//-------------------------destructor
ListaDobleEnlazada::~ListaDobleEnlazada(){}