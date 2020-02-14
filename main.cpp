#include "Ventana.h"
#include "iostream"
#include "ListaDobleEnlazada.h"
#include "ListaCircular.h"
#include "Pila.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 */

int main(){
    Ventana principal;
    /*
    string nombre;
    int largoVentana=100, altoVentana=100;
    //marcos
    for (int i = 0; i <=largoVentana; i++)
    {
        gotoxy(i,0);
        cout<<"*";
    }    
    gotoxy(10,10);
    cout<<"Ingrese un nombre: ";
    cin>>nombre;
    gotoxy(20,20);
    cout<<"lo nombre ingresado es: "<<nombre;
    getch();

    /*
    for(int i=0;i<=50;i++){
        gotoxy(i,0);
        printf("*");        
    }  
      getch();
    
    initscr();               //Initiate curses mode           
    printw("Hello world\n"); //write "Hello world" to the standard screen 
    refresh();               //print any changes done to the standard screen
    
    getch();                 //Wait for user input
    endwin();                //End curses mode
    
    Pila p;
    p.Push("hector");
    p.Push("josue");
    p.Push("orozco");
    p.Push("salazar");
    p.generarDot();
    p.generarImagen();
    
    ListaCircular c;
    c.insertarNodo("a","a");
    c.insertarNodo("b","b");
    c.insertarNodo("c","c");
    c.insertarNodo("a","a");
    c.insertarNodo("b","b");
    c.insertarNodo("c","c");
    c.imprimirLista();
    c.generarDot();
    c.generarImagen();
    
    ListaDobleEnlazada list;
    list.insertarNodo('h');
    list.insertarNodo('e');
    list.insertarNodo('c');
    list.insertarNodo('t');
    list.insertarNodo('o');
    list.insertarNodo('r');
    list.imprimirLista();
    list.generarDot();
    list.generarImagen();
    */
    return 0;
}