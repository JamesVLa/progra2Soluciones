//
// Created by james on 6/11/2025.
//

#include "Comunes.h"
#include <cstring>

void liberarCadena(char* &cadena) {
    if (!cadena) {
        delete[] cadena;
        cadena= nullptr;
    }
}
char* miString(const char* cad) {
    if (!cad)return nullptr;
    char* copia=new char[strlen(cad)+1];
    strcpy(copia,cad);
    return copia;
}