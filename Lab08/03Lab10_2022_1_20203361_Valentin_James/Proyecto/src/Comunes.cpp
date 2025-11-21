//
// Created by james on 21/11/2025.
//

#include "Comunes.h"
void liberarCadena(char *&cad) {
    if (cad) {
        delete[] cad;
        cad = nullptr;
    }
}

char *miString(const char *cad) {
    if (!cad)return nullptr;
    char* cadena = new char[strlen(cad) + 1];
    strcpy(cadena, cad);
    return cadena;
}

void imprimirLinea(ostream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++) {
        arch<<c;
    }
    arch<<endl;
}

void sacarFecha(int fecha, int &dd, int &mm, int &yyyy) {
    dd=fecha%100;
    fecha=fecha/100;
    mm=fecha%100;
    yyyy=fecha/100;
}

