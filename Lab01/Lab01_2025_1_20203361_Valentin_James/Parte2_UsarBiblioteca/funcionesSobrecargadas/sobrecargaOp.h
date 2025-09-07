//
// Created by james on 3/09/2025.
//

#ifndef PARTE1_CREARBIBLIOTECA_SOBRECARGAOP_H
#define PARTE1_CREARBIBLIOTECA_SOBRECARGAOP_H
#include "CadenaDeCaracteres .h"
#include <iostream>
#include <fstream>

using namespace std;

void operator !(struct CadenaDeCaracteres &cad);

void operator <=(CadenaDeCaracteres &cad, int cantidad);
void operator <=(CadenaDeCaracteres cadena, const char *&cad);
void operator <=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

bool operator+=(CadenaDeCaracteres& cad, const char* texto);
bool operator+=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

char toLowerChar(char c);
int compare(const CadenaDeCaracteres& cad, const char* texto);

bool operator==(const CadenaDeCaracteres& cad, const char* texto);
bool operator<(const CadenaDeCaracteres& cad, const char* texto);
bool operator>(const CadenaDeCaracteres& cad, const char* texto);

int compare(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2);

bool operator==(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2);
bool operator<(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2);
bool operator>(const CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2);


int operator>>(ifstream& in, CadenaDeCaracteres& cad);

void operator&&(CadenaDeCaracteres& cad1, CadenaDeCaracteres& cad2);


ofstream& operator<<(ofstream& out, const CadenaDeCaracteres& cad);

#endif //PARTE1_CREARBIBLIOTECA_SOBRECARGAOP_H