/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tablero.cpp
 * Author: juanan
 * 
 * Created on 8 de julio de 2024, 18:08
 */

#include <valarray>
#include "Tablero.h"
#include <string>
#include <iostream>
using namespace std;

Tablero::Tablero(int f, int c, int numbombas){
    inicializarTablero(f,c,numbombas);
}
//se inicializan las matrices a 2 matrices vacías con todo a 0
void Tablero::inicializarVariables(int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            tab.putValue(i,j) = 0;
        }
    }
    
}

void Tablero::inicializarTablero(int f, int c, int numbombas){
    inicializarVariables(f,c);
    colocarBombas(numbombas);
    calculardistancias();
}

Tablero::Tablero(const Tablero & orig){
    tab.resize(orig.tab.numfilas(),orig.tab.numcolumnas(),0);
    for(int i=0; i<tab.numfilas(); i++){
        for(int j=0; j<tab.numcolumnas(); j++){
           tab.putValue(i,j) = orig.tab.getValue(i,j); 
        }    
    }
    descubierto.resize(orig.descubierto.numfilas(), orig.descubierto.numcolumnas(),0);
    for(int i=0; i<descubierto.numfilas(); i++){
        for(int j=0; j<descubierto.numcolumnas(); j++){
           descubierto.putValue(i,j) = orig.descubierto.getValue(i,j); 
        }    
    }
}

//muestra toda la información del tablero
string Tablero::mostrarTableroEntero(){
    return tab.matriztostring();
}
Tablero::Tablero(){
    inicializarTablero(7,7,9);
}
//muestra toda la información de lo que se ha abierto, lo que está cerrado
//y lo que está marcado
string Tablero::mostrarDescubierto(){
    return descubierto.matriztostring();
}
//Muestra el tablero tal y como lo debe de ver el jugador en el juego.
string Tablero::mostrarTableroaJugador(){
    string resultado;
    resultado = "";
    for(int i=0; i<descubierto.numfilas(); i++){
        for(int j=0; j<descubierto.numcolumnas(); j++){
            if(descubierto.getValue(i,j)==0){
                resultado += "? ";
            }
            else if(descubierto.getValue(i,j)==1){
                resultado += to_string(tab.getValue(i,j)) + " ";
            }
            else if(descubierto.getValue(i,j)==2){
                resultado += "B ";
            }
        }
        resultado += "\n";
    }
    return resultado;
}

//este método coloca aleatoriamente las bombas por el tablero
void Tablero::colocarBombas(int numbombas){
    int filas = tab.numfilas();
    int columnas = tab.numcolumnas();
    for(int i=0; i<numbombas; i++){
        int numeroaleatorio1;
        int numeroaleatorio2;
        do{
        numeroaleatorio1 = GeneradorAleatorios(0,filas -1);
        numeroaleatorio2 = GeneradorAleatorios(0,columnas -1);
        }while(tab.getValue(numeroaleatorio1,numeroaleatorio2)== NUMBOMBA);
        tab.putValue(numeroaleatorio1,numeroaleatorio2) = NUMBOMBA;
    }
}
//este metodo calcula el numero de bombas que hay alrededor de cada casilla
void Tablero::calculardistancias(){
    for(int i=0; i<tab.numfilas(); i++){
        for(int j=0; j<tab.numcolumnas(); j++){
            if(tab.getValue(i,j)!= NUMBOMBA){
                int valor = 0;
                for(int x=i-1; x<=i+1; x++){
                    for(int y=j-1; y<=j+1; y++){
                        if(x>=0 && x<tab.numfilas() && y>=0 && y<tab.numcolumnas()){
                            if(tab.getValue(x,y)== NUMBOMBA){
                                valor++;    
                            }
                        }
                    }
                }
                tab.putValue(i,j) = valor;
            }
        }
    }
}

void Tablero::saveFichero(string fich){
     ofstream fichero;
     string resultado;
     resultado = "";
     resultado += to_string(tab.numfilas()) + to_string(tab.numcolumnas()) + "\n";
     for(int i=0; i<tab.numfilas(); i++){
         for(int j=0; j<tab.numcolumnas(); j++){
             resultado += to_string(tab.getValue(i,j)) + " ";
         }
         resultado += "\n";
     }
     resultado += "\n";
     for(int i=0; i<descubierto.numfilas(); i++){
         for(int j=0; j<descubierto.numcolumnas(); j++){
             resultado += to_string(descubierto.getValue(i,j)) + " ";
         }    
         resultado += "\n";
     }
     fichero.open("./data/" + fich);
     if(fichero.is_open()){
         fichero << resultado;
         fichero.close();
     }
    
 }
 
 void Tablero::loadFichero(string fich){
     ifstream fichero;
     string resultado;
     resultado = "";
     resultado += to_string(tab.numfilas()) + to_string(tab.numcolumnas()) + "\n";
     for(int i=0; i<tab.numfilas(); i++){
         for(int j=0; j<tab.numcolumnas(); j++){
             resultado += to_string(tab.getValue(i,j));
         }
         resultado += "\n";
     }
     resultado += "\n";
     for(int i=0; i<descubierto.numfilas(); i++){
         for(int j=0; j<descubierto.numcolumnas(); j++){
             resultado += to_string(descubierto.getValue(i,j));
         }
         resultado += "\n";
     }
     fichero.open("./data/" + fich);
     if(fichero.is_open()){
         fichero >> resultado;
         fichero.close();
     }
 }
 
 int Tablero::GeneradorAleatorios(int min, int max){
        random_device generador;
        uniform_int_distribution<int> distributionnum(min,max);
        int numeroaleatorio = distributionnum(generador);
        return numeroaleatorio;
 }
 
