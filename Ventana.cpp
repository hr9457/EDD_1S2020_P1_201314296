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
        cout<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"FACULTAD DE INGENIERIA";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"PRACTICA 1";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"HECTOR JOSUE OROZCO SALAZAR";
        lineaMenu=lineaMenu+1;
        gotoxy(centroMenu,lineaMenu);
        cout<<"201314296";
        lineaMenu=lineaMenu+5;

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
     }else if(op==50){
         system("cls");
         gotoxy(10,10);
         cout<<"Ruta Archivo: ";
         do{
             caracter = getch();
             cout<<caracter;
             if(caracter!=13){
                 rutaArchivo = rutaArchivo + caracter;
             }             
         }while(caracter!=13);
         //apertura de la ventana
         VentanaEdit ventanaEdiccion2(rutaArchivo);
     }else{

     }

 }

//destructor de la ventana
Ventana::~Ventana(){}
