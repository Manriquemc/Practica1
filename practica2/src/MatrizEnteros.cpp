/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MatrizEnteros.cpp
 * Author: juanan
 * 
 * Created on 8 de julio de 2024, 13:14
 */

#include "MatrizEnteros.h"
#include <iostream>
#include <string>
using namespace std;


int MatrizEnteros::numfilas() const{
    return fil;
}
int MatrizEnteros::numcolumnas() const{
    return col;
}

int & MatrizEnteros:: putValue(int fil, int col){
    return m[fil][col];
}

int MatrizEnteros::getValue(int fil, int col) const{
    return m[fil][col];
}

MatrizEnteros::MatrizEnteros(int newfil, int newcol, int def) {
    fil = newfil;
    col = newcol;
    m = new int *[fil];
    for(int i=0; i<fil; i++){
        m[i] = new int [col];
    }
    inicializarMatriz(def);
}

void MatrizEnteros::inicializarMatriz(int def){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j]= def;
        }
    }
}
//vacio
MatrizEnteros::MatrizEnteros(const MatrizEnteros& orig) {
    fil = orig.fil;
    col = orig.col;
    m = new int * [fil];
    for(int i=0; i<fil; i++){
        m[i] = new int [col];
    }
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j] = orig.m[i][j];
        }
    }
    
}
//vacio
MatrizEnteros::~MatrizEnteros() {
    for(int i=0; i<fil; i++){
        delete[] m[i];
    }
    delete[] m;
}
string MatrizEnteros::matriztostring(){
    string resultado = "";
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            resultado += to_string(m[i][j]) + " ";
        }
        resultado += "\n";
    }
    return resultado;
}

void MatrizEnteros::resize(int newf, int newc, int value) {
    int **nuevam;
    nuevam = new int *[newf];
    for (int i = 0; i < newf; i++) {
        nuevam[i] = new int[newc];
    }

    // Copiar los valores existentes a la nueva matriz
    for (int i = 0; i < std::min(fil, newf); i++) {
        for (int j = 0; j < std::min(col, newc); j++) {
            nuevam[i][j] = m[i][j];
        }
    }

    // Inicializar los nuevos elementos en la nueva matriz
    for (int i = 0; i < newf; i++) {
        for (int j = 0; j < newc; j++) {
            if (i >= fil || j >= col) {
                nuevam[i][j] = value;
            }
        }
    }

    // Liberar la memoria de la matriz anterior
    for (int i = 0; i < fil; i++) {
        delete[] m[i];
    }
    delete[] m;

    // Asignar la nueva matriz y actualizar las dimensiones
    m = nuevam;
    fil = newf;
    col = newc;
}

