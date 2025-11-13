//
// Created by james on 12/11/2025.
//

#include "Comunes.h"

void liberarCadena(char* &cadena) {
    if (!cadena) {
        delete[] cadena;
        cadena = nullptr;
    }
}
char* miString(const char* cad) {
    if (!cad)return nullptr;
    char* copia=new char[strlen(cad)+1];
    strcpy(copia,cad);
    return copia;
}
void imprimirLinea(ofstream& arch, int cant,char c) {
    for (int i = 0; i < cant; i++) {
        arch<<c;
    }
    arch<<endl;
}