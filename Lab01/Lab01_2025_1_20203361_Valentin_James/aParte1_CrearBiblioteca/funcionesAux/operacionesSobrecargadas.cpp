//
// Created by james on 1/09/2025.
//
#include "operacionesSobrecargadas.h"
#include <fstream>
#include <cstring>
using namespace std;
void operator!(CadenaDeCaracteres& cad) {
    if (cad.cadena) { // por si ya tiene algo xd
        delete[] cad.cadena;
    }
    cad.cadena = nullptr;
    cad.longitud = 0;
    cad.capacidad = 0;
}

void operator<=(CadenaDeCaracteres& cad, int cantidad) {// asignamos espacio de memoria
    !cad;//inicializamos
    cad.cadena = new char[cantidad];
    cad.capacidad = cantidad;
    cad.cadena[0] = '\0';
}

void operator<=(CadenaDeCaracteres& cad, const char* texto) {
    int necesaria = strlen(texto) + 1;
    if (cad.capacidad<necesaria)cad <= necesaria;
    strcpy(cad.cadena, texto);
    cad.longitud = necesaria - 1;
}

void operator<=(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    if (cad2.cadena == nullptr) {//por si por alguna razón hay algun null
        !cad1; // inicializamos
        return;
    }
    cad1 <= cad2.cadena;
}

bool operator+=(CadenaDeCaracteres& cad, const char* texto) {
    if (cad.cadena == nullptr || cad.longitud == 0) return false;
    if (texto == nullptr || strlen(texto) == 0) return true;

    int nuevaLongitud = cad.longitud + strlen(texto);

    if (cad.capacidad < nuevaLongitud + 1) {
        CadenaDeCaracteres copia{};
        !copia;
        copia <= cad.cadena;
        copia <= nuevaLongitud + 1;
        strcpy(copia.cadena, cad.cadena);
        strcat(copia.cadena, texto);

        !cad;
        cad <= copia.cadena;
    } else {
        strcat(cad.cadena, texto);
    }

    cad.longitud = nuevaLongitud;
    return true;
}

bool operator+=(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    if (cad1.cadena == nullptr || cad1.longitud == 0) return false;
    if (cad2.cadena == nullptr || cad2.longitud == 0) return true;

    return (cad1 += cad2.cadena);
}

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}


int compare(const CadenaDeCaracteres& cad, const char* texto) {
    int i = 0;
    while (cad.cadena[i] != '\0' && texto[i] != '\0') {
        char a = toLowerChar(cad.cadena[i]);
        char b = toLowerChar(texto[i]);
        if (a != b) return (a - b);
        i++;
    }
    return toLowerChar(cad.cadena[i]) - toLowerChar(texto[i]);
}

bool operator==(const CadenaDeCaracteres& cad, const char* texto) {
    return compare(cad, texto) == 0;
}
bool operator<(const CadenaDeCaracteres& cad, const char* texto) {
    return compare(cad, texto) < 0;
}
bool operator>(const CadenaDeCaracteres& cad, const char* texto) {
    return compare(cad, texto) > 0;
}

int compare(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return compare(cad1, cad2.cadena);
}

bool operator==(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return compare(cad1, cad2) == 0;
}
bool operator<(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return compare(cad1, cad2) < 0;
}
bool operator>(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return compare(cad1, cad2) > 0;
}

int operator>>(ifstream& in, CadenaDeCaracteres& cad) {
    char buffer[1024];
    in>>buffer;
    if (in.eof()) return 1;

    char c = buffer[0];
    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) return -1;

    cad <= buffer;
    return 0;
}

void operator&&(CadenaDeCaracteres& cad1, CadenaDeCaracteres& cad2) {
    CadenaDeCaracteres temp{};
    !temp;
    temp <= cad1;
    cad1 <= cad2;
    cad2 <= temp;
}


ofstream& operator<<(ofstream& out, const CadenaDeCaracteres& cad) {
    if (cad.cadena) {
        out << cad.cadena;
    }
    return out;
}
