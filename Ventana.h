#ifndef VENTANA_H
#define VENTANA_H

#include "VentanaEdicion.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Ventana
{
    private:
        int largoVentana=110, centorMenus=30;
        string opMenu;

    public:
        void gotoxy(int posx,int posy);
        Ventana();
        void CreacionMarco();
        void menu();
        void selecionMenu(string arg);
        ~Ventana();
};

#endif