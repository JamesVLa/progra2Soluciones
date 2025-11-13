//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_COMUNES_H
#define PROYECTO_COMUNES_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#define TAM_LINEA 80
using namespace std;

void liberarCadena(char* &cadena);
char* miString(const char* cad);
void imprimirLinea(ofstream& arch, int cant,char c);
// void imprimirLinea(ofstream& arch,TAM_LINEA,'=');
#endif //PROYECTO_COMUNES_H