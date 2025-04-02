/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanan
 *
 * Created on 8 de julio de 2024, 13:08
 */

#include <cstdlib>
#include "MatrizEnteros.h"
#include "Tablero.h"
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    MatrizEnteros a(3,4,-1);
    cout << a.matriztostring();
    cout << endl;
    a.resize(7,7,-1);
       cout << a.matriztostring();
    cout << endl;
    a.putValue(3,3) = 4;
    cout << a.matriztostring();
    cout << endl;
    a.resize(2,2,4);
      cout << a.matriztostring();
    cout << endl;

   Tablero buscam(8,8,5);
   cout <<  buscam.mostrarTableroEntero();
    cout << endl;
   cout <<  buscam.mostrarDescubierto();
    cout << endl;
    cout << buscam.mostrarTableroaJugador() << endl;
    
    buscam.saveFichero("tab.txt");
    Tablero buscam2(3,3,1);
    buscam2.loadFichero("tab.txt");
    cout << buscam2.mostrarTableroEntero() << endl;
    cout << buscam2.mostrarDescubierto() << endl;
    return 0;
}

