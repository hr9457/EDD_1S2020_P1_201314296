#include "VentanaEdit.h"


//----------Contructor
VentanaEdit::VentanaEdit(){    
    marco();
    ediccion();
}



//funcion de pintado en el  consola 
void VentanaEdit::gotoxy(int posx,int posy){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = posx;  
      dwPos.Y= posy;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }



//-------------------------Dibuja el marco y el menu del la ediccion
void VentanaEdit::marco(){
    for(int ColumnaMarco=0;ColumnaMarco<=finalPantalla;ColumnaMarco++){
        gotoxy(ColumnaMarco,0);
        cout<<"-";  
    }

    for(int ColumnaMarco=0;ColumnaMarco<=finalPantalla;ColumnaMarco++){
        gotoxy(ColumnaMarco,altoPantalla);
        cout<<"-";  
    }

    //------MENU EDICCION-------
    gotoxy(inicioMenu,altoPantalla+1);
    cout<<"Esc(Salir)";

    gotoxy(inicioMenu+12,altoPantalla+1);
    cout<<"^w(Buscar y Remplazar)";

    gotoxy(inicioMenu+36,altoPantalla+1);
    cout<<"^c(Reportes)";

    gotoxy(inicioMenu+50,altoPantalla+1);
    cout<<"^s(Guardar)";
    gotoxy(1,1);//posicion cursos 
}



//-----------------Repintado de pantalla
void VentanaEdit::Repintar(){
    system("cls");
    marco();
    //recorrido de la lista
    NodoListaDoble *elPrimero = listaDoble.getPrimero();
    
    while (elPrimero!=NULL)
    {
        gotoxy(elPrimero->getPosx(),elPrimero->getPosy());
        cout<<elPrimero->getLetra();
        elPrimero=elPrimero->siguiente;

    }
    NodoListaDoble *elUltimo = listaDoble.getUltimo();
    columna = elUltimo->getPosx()+1;
    saltoLinea = elUltimo->getPosy();
    gotoxy(columna,saltoLinea);
        
}



//-------------------Metodo para crear un archivo
void VentanaEdit::guardar(string ruta){
    int salto;
    ofstream archivo("Save\\"+ruta+".txt");
    NodoListaDoble *inicio = listaDoble.getPrimero();
    salto = inicio->getPosy();
    while(inicio!=NULL){
        if(inicio->getLetra()!='\n'){
            archivo<<inicio->getLetra();
            inicio=inicio->siguiente;
        }else{
            archivo<<endl;
            inicio=inicio->siguiente;
        }
        
    }
    archivo.close(); 
}



//----------funcionalidad para la ediccion de la pantalla 
 void VentanaEdit::ediccion(){
     do
     {
        //entrada del teclado del usuario
        inKeyboard=caracter=getch();

        if(columna<finalPantalla && saltoLinea<altoPantalla){


            if(inKeyboard==32){//para barra espaciadora
                gotoxy(columna,saltoLinea);
                cout<<caracter;
                columna=columna+1;
                //insertar espacio en blanco en el nodo
                listaDoble.insertarNodo(' ',columna,saltoLinea);


            }else if(inKeyboard==8){//para borrar
                columna=columna-1;
                gotoxy(columna,saltoLinea);
                cout<<" ";
                gotoxy(columna,saltoLinea);
                //eliminando nodo en la lista
                listaDoble.eliminarNodo();
                      

            }else if(inKeyboard==13){//para salto de linea
                //columna=columna+1;
                listaDoble.insertarNodo('\n',columna+1,saltoLinea);
                saltoLinea=saltoLinea+1;
                columna=1;
                gotoxy(columna,saltoLinea);


            }else if(inKeyboard==19){//para Ctrl+S
                //para busqueda de palabras
                gotoxy(columnaBuscar+65,altoPantallaBuscar+1);
                cout<<"Nombre: ";
                 do{
                    caracter=getch();
                    cout<<caracter;
                    if(caracter!=13){
                        rutaArchivo=rutaArchivo+caracter;
                    }    
                }while(caracter!=13);
                guardar(rutaArchivo);
                Repintar();

            

            }else if(inKeyboard==3){//para Ctrl+C
                //reporte de la lista doblemente enlazada
                listaDoble.generarDot();
                listaDoble.generarImagen();



            }else if(inKeyboard==23){//para Ctrl+w
                //para busqueda de palabras
                gotoxy(columnaBuscar+65,altoPantallaBuscar+1);
                cout<<"Buscar y Remplazar: ";
                //gotoxy(columna+85,altoPantalla+1);
                //entrada del teclado del usuario   
                            
                do{
                    caracter=getch();
                    cout<<caracter;
                    if(caracter!=59){
                        palabraBuscar=palabraBuscar+caracter;
                    }                    
                }while(caracter!=59);

                do{
                    caracter=getch();
                    cout<<caracter;
                    if(caracter!=13){
                        palabraRemplazar=palabraRemplazar+caracter;
                    }
                }while(caracter!=13);

               //llamando al metodo para buscar y remplazar en la lista
                listaDoble.buscarPalabra(palabraBuscar,palabraRemplazar);
                //palabraBuscar=" ";
                //palabraRemplazar=" ";
                Repintar();
                this->palabraBuscar=" ";
                this->palabraRemplazar=" ";


            }else{//para escribir en el editor
                gotoxy(columna,saltoLinea);
                cout<<caracter;
                columna=columna+1;
                //ingreso caractera a a la lista
                listaDoble.insertarNodo(caracter,columna,saltoLinea);

            }
            
        }//fin del limites del marco 


     } while (inKeyboard!=27);     
 }



//--------------Destructor
VentanaEdit::~VentanaEdit(){}