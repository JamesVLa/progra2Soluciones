//
// Created by james on 13/11/2025.
//

#include "Comunes.h"

void liberarCadena(char *&cadena) {
    if (cadena) {
        delete[] cadena;
        cadena = nullptr;
    }
}

char* miString(const char *cad) {
    char* cadena;
    if (!cad) return nullptr;
    cadena = new char[strlen(cad) + 1];
    strcpy(cadena, cad);
    return cadena;
}

void imprimirLinea(ostream& arch, int cant,char c) {
    for (int i = 0; i < cant; i++) {
        arch<<c;
    }
    arch<<endl;
}
