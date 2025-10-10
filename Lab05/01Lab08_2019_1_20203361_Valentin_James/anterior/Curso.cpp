//
// Created by james on 7/10/2025.
//

#include "Curso.h"

#include <cstring>


Curso::Curso() {
    this->codigo = nullptr;
    this->nombre = nullptr;
    this->creditos = 0;
    this->requisitos = 0;
    this->numRequisitos = 0;
}

Curso::Curso(const Curso &curso) : Curso() {
    *this = curso;
}

char *Curso::getCodigo() const {
    if (!codigo) return nullptr;
    char *copia = new char[strlen(codigo) + 1];
    strcpy(copia, codigo);
    return copia;
}

void Curso::setCodigo(char *codigo) {
    delete[] this->codigo;
    if (codigo) {
        this->codigo = new char[strlen(codigo) + 1];
        strcpy(this->codigo, codigo);
    } else {
        this->codigo = nullptr;
    }
}

char *Curso::getNombre() const {
    if (!nombre) return nullptr;
    char *copia = new char[strlen(nombre) + 1];
    strcpy(copia, nombre);
    return copia;
}

void Curso::setNombre(char *nombre) {
    delete [] this->nombre;
    if (nombre) {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
    } else {
        this->nombre = nullptr;
    }
}

double Curso::getCreditos() const {
    return creditos;
}

void Curso::setCreditos(double creditos) {
    this->creditos = creditos;
}

char **Curso::getRequisitos() const {
    if (!requisitos) return nullptr;
    int contador = numRequisitos;

    // while (requisitos[contador] != nullptr) ++contador;

    char **copia = new char *[contador + 1];

    for (int i = 0; i < contador; ++i) {
        copia[i] = new char[strlen(requisitos[i]) + 1];
        strcpy(copia[i], requisitos[i]);
    }
    copia[contador] = nullptr;

    return copia;
}

void Curso::setRequisitos(char **requisitos) {
    //primero veo si tiene algo
    if (this->requisitos) {
        //si tiene algo lo elimino
        for (int i = 0; this->requisitos[i] != nullptr; ++i) {
            delete[] this->requisitos[i];
        }
        delete[] this->requisitos;
    }
    if (requisitos) {
        int contador = 0;
        while (requisitos[contador] != nullptr) ++contador;
        this->requisitos = new char *[contador + 1];
        for (int i = 0; i < contador; ++i) {
            this->requisitos[i] = new char[strlen(requisitos[i]) + 1];
            strcpy(this->requisitos[i], requisitos[i]);
        }
        this->requisitos[contador] = nullptr;
        this->numRequisitos = contador; // aca así o
        // setNumRequisitos(contador);
        // this->setNumRequisitos(contador);
    } else {
        this->requisitos = nullptr;
        this->numRequisitos = 0;
        // setNumRequisitos(0);
        // this->setNumRequisitos(0);
    }
}

int Curso::getNumRequisitos() const {
    return numRequisitos;
}

void Curso::setNumRequisitos(int numRequisitos) {
    this->numRequisitos = numRequisitos;
}

// Curso& Curso::operator=(const Curso& curso) {
//     if (this == &curso) return *this;
//     char* tempCodigo = curso.getCodigo();
//     char* tempNombre = curso.getNombre();
//     char** tempReq = curso.getRequisitos();
//     setCodigo(tempCodigo);
//     setNombre(tempNombre);
//     setCreditos(curso.getCreditos());
//     setRequisitos(tempReq);
//     setNumRequisitos(curso.getNumRequisitos());
//     delete[] tempCodigo;
//     delete[] tempNombre;
//     if (tempReq) {
//         for (int i = 0; tempReq[i] != nullptr; ++i)
//             delete[] tempReq[i];
//         delete[] tempReq;
//     }
//     return *this;
// }

Curso &Curso::operator=(const Curso &curso) {
    if (this == &curso) {
        return *this;
    }
    this->setCodigo(curso.codigo);
    this->setNombre(curso.nombre);
    this->setCreditos(curso.creditos);
    this->setRequisitos(curso.requisitos);
    this->setNumRequisitos(curso.numRequisitos);
    // preguntar esto
    // this->setCodigo(curso.getCodigo());
    // this->setNombre(curso.getNombre());
    // this->setCreditos(curso.getCreditos());
    // this->setRequisitos(curso.getRequisitos());
    // this->setNumRequisitos(curso.getNumRequisitos());
    return *this;
}

Curso::~Curso() {
    delete[] this->codigo;
    delete[] this->nombre;
    // delete[] this->requisitos; esto estaba mal no?
    if (this->requisitos) {
        for (int i = 0; this->requisitos[i] != nullptr; ++i) {
            delete[] this->requisitos[i];
        }
        delete[] this->requisitos;
    }
}

void Curso::agregarRequisito(const char *nuevoRequisito) {
    char **nuevoArr = new char *[numRequisitos + 2];
    for (int i = 0; i < numRequisitos; ++i) {
        if (requisitos)
            nuevoArr[i] = requisitos[i];
        else
            nuevoArr[i] = nullptr;
    }
    nuevoArr[numRequisitos] = new char[strlen(nuevoRequisito) + 1];
    strcpy(nuevoArr[numRequisitos], nuevoRequisito);
    nuevoArr[numRequisitos + 1] = nullptr;

    if (requisitos)delete[] requisitos;
    requisitos = nuevoArr;
    numRequisitos++;
}

char *Curso::obtenerRequisito(int pos) const {
    if (!requisitos || pos < 0 || pos >= numRequisitos) return nullptr; // o le pongo un exit(1)?
    char *copia = new char[strlen(requisitos[pos]) + 1];
    strcpy(copia, requisitos[pos]);
    return copia;
}
