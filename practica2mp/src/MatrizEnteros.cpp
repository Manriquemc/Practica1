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


int MatrizEnteros::numfilas(){
    return fil;
}
int MatrizEnteros::numcolumnas(){
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

void MatrizEnteros::resize(int newf, int newc, int value){
    int **nuevam;
    nuevam = new int * [newf];
    for(int i=0; i<newf; i++){
        nuevam[i] = new int [newc];
    }
    for(int i=0; i<min(fil,newf); i++){
        for(int j=0; j<min(col,newc); j++){
            nuevam[i][j] = m[i][j];
        }
    }
    for(int i=fil; i<newf; i++){
        for(int j=col; j<newc; j++){
                nuevam[i][j] = value;
        }
    }
    for(int i=0; i<fil; i++){
        delete[] m[i];
    }
    delete[] m;
    
    m = nuevam;
    fil = newf;
    col = newc;
}

