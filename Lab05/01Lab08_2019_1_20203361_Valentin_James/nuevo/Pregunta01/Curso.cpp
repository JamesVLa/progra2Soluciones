//
// Created by james on 8/10/2025.
//

#include "Curso.h"
#include <cstring>

char * Curso::getCodigo() const {
    if (!this->codigo)return nullptr;
    char *copia=new char[strlen(this->codigo)+1];
    strcpy(copia, this->codigo);
    return copia;
}

void Curso::setCodigo(char *cod) {
    delete [] this->codigo;
    if (cod) {
        this->codigo = new char[strlen(cod)+1];
        strcpy(this->codigo, cod);
    }else {
        this->codigo=nullptr;
    }
}

char * Curso::getNombre() const {
    if (!this->nombre)return nullptr;
    char *copia=new char[strlen(nombre)+1];
    strcpy(copia, nombre);
    return copia;
}

void Curso::setNombre(char *nomb) {
    delete [] this->nombre;
    if (!nomb) {
        this->nombre= new char[strlen(nomb)+1];
        strcpy(this->nombre, nomb);
    }else {
        this->nombre=nullptr;
    }
}

double Curso::getCreditos() const {
    return creditos;
}

void Curso::setCreditos(double creditos) {
    this->creditos = creditos;
}

char ** Curso::getRequisitos() const {
    if (!this->requisitos)return nullptr;
    int contador=getNumRequisitos();
    char **copia=new char *[contador+1];

    for (int i = 0; i < contador; i++) {
        copia[i]=new char[strlen(this->requisitos[i])+1];
        strcpy(copia[i], this->requisitos[i]);
    }
    copia[contador]=nullptr;
    return copia;
}

void Curso::setRequisitos(char **requi) {
    if (this->requisitos) {// primero elimino si esque hay algun requisito
        for (int i = 0; i < this->numRequisitos; i++) {
            delete [] this->requisitos[i];
        }
        delete [] this->requisitos;
    }
    if (requi) {// si esque hay datos
        int contadorRequisitos=0;
        while (requi[contadorRequisitos]!=nullptr) contadorRequisitos++;
        this->requisitos=new char *[contadorRequisitos+1];
        for (int i = 0; i < contadorRequisitos; i++) {
            this->requisitos[i]=new char[strlen(requi[i])+1];
            strcpy(this->requisitos[i], requi[i]);
        }
        this->requisitos[contadorRequisitos]=nullptr;
        this->numRequisitos=contadorRequisitos;
    }else {// si no hay datos
        this->requisitos=nullptr;
        this->numRequisitos=0;
    }
}

int Curso::getNumRequisitos() const {
    return numRequisitos;
}

void Curso::setNumRequisitos(int numRequisitos) {
    this->numRequisitos = numRequisitos;
}

Curso::~Curso() {
    delete [] this->codigo;
    delete [] this->nombre;
    if (this->requisitos) {
        for (int i = 0; i < this->numRequisitos; i++) {
            delete [] this->requisitos[i];
        }
    }
    delete [] this->requisitos;
}
