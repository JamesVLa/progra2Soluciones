//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_COMUNES_H
#define PROYECTO_COMUNES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void liberarCadena(char* &cad);
void sacarFecha(int fecha,int &dd, int &mm, int &yyyy);
char* miString(const char* cad);

void imprimirLinea(ostream &arch, int cant, char c);
#endif //PROYECTO_COMUNES_H