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
    gotoxy(columna,altoPantalla+1);
    cout<<"Esc(Salir)";

    gotoxy(columna+14,altoPantalla+1);
    cout<<"^w(Buscar y Remplazar)";

    gotoxy(columna+40,altoPantalla+1);
    cout<<"^c(Reportes)";

    gotoxy(columna+55,altoPantalla+1);
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