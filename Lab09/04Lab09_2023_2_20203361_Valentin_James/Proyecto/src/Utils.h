//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_UTILS_H
#define PROYECTO_UTILS_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
void imprimirLinea(ofstream &arch,char c, int tam);
void aperturaArchivoEntrada(ifstream &arch,const char*nomb);
void aperturaArchivoSalida(ofstream &arch, const char *nomb);

#endif //PROYECTO_UTILS_H