#include "VentanaEdit.h"

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
                saltoLinea=saltoLinea+1;
                columna=1;
                gotoxy(columna,saltoLinea);


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
                gotoxy(columna,saltoLinea);


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

VentanaEdit::~VentanaEdit(){}