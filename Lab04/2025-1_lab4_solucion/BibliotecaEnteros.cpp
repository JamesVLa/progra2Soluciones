//
// Created by SEMACS on 2/10/2025.
//
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaEnteros.h"

using namespace std;

bool leenum(ifstream &arch,void*& dato) {
    int numero;
    arch >> numero;
    if (arch.eof()) return false;
    dato=new int(numero);
    return true;
}

int calsificaentero(void *dato) {
    if (*(int *)dato<10) {
        return 1;
    }
    else {
        return 2;
    }
}

void imprimenum(ofstream &arch,void*dato,int numIteracion) {
    arch<<*(int *)dato<<endl;
}