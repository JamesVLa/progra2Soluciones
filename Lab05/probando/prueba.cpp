//
// Created by james on 8/10/2025.
//

#include "prueba.h"
#include <iostream>
#include <cstring>
using namespace std;

prueba::prueba() {
    textoBien = nullptr;
    textoMal = nullptr;
}

prueba::~prueba() {
    cout << "Llamando al destructor..." << endl;

    delete[] textoBien;

    cout << "  -> textoBien liberado" << endl;

    delete[] textoMal;
    cout << "  -> textoMal liberado" << endl;
    cout << "(Destructor completado)" << endl;
}

void prueba::setTextoBien(const char* txt) {
    delete[] textoBien;
    textoBien = new char[strlen(txt) + 1];
    strcpy(textoBien, txt);
}

void prueba::setTextoMal(const char* txt) {
    delete[] textoMal;
    textoMal = new char[strlen(txt) + 1];
    strcpy(textoMal, txt);
}

char* prueba::getTextoBien() const {
    if (!textoBien) return nullptr;

    char* copia = new char[strlen(textoBien) + 1];
    strcpy(copia, textoBien);
    return copia;
}

char* prueba::getTextoMal() const {
    return textoMal;
}