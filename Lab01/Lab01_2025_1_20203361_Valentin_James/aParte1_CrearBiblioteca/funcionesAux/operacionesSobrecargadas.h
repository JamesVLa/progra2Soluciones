//
// Created by james on 1/09/2025.
//

#ifndef PARTE1_CREARBIBLIOTECA_OPERACIONESSOBRECARGADAS_H
#define PARTE1_CREARBIBLIOTECA_OPERACIONESSOBRECARGADAS_H
#include "CadenaDeCaracteres.h"
#include <fstream>
using namespace std;
void operator!(CadenaDeCaracteres& );

void operator<=(CadenaDeCaracteres& , int );
void operator<=(CadenaDeCaracteres& , const char* );
void operator<=(CadenaDeCaracteres& , const CadenaDeCaracteres& );

bool operator+=(CadenaDeCaracteres& , const char* );
bool operator+=(CadenaDeCaracteres& , const CadenaDeCaracteres& );

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

#endif //PARTE1_CREARBIBLIOTECA_OPERACIONESSOBRECARGADAS_H