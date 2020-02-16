#include "Ventana.h"

//contructor de la ventana
Ventana::Ventana(){
    //inicio para la ventan
    //VentanaEdit crea;
    
    menu();
}

//funcion de pintado en el  consola 
void Ventana::gotoxy(int posx,int posy){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = posx;  
      dwPos.Y= posy;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }

 void Ventana::menu(){
     do
     {
        system("cls");//limpieza de pantalla
        system("color 2");
        //gotoxy(110,2);
        //gotoxy(1,1);
        //cout<<"ancho: "<<ancho<<" alto: "<<alto;
        lineaMenu=5;
        gotoxy(centroMenu,lineaMenu);
        cout<<"MENU";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"1. Crear Archivo";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"2. Abrir Archivo";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"3. Salir";
        lineaMenu=lineaMenu+1;
        inKeyborad=getch();//entrdad de teclado   
        cout<<"valor entrada es: "<<inKeyborad;
        opMenu(inKeyborad);
     } while (inKeyborad!=51);      
 }

 void Ventana::opMenu(int op){
     if(op==49){
         system("cls");
         VentanaEdit ventanaEdiccion;
     }else{
     }

 }

//destructor de la ventana
Ventana::~Ventana(){}
