//
// Created by james on 7/10/2025.
//

#include "Alumno.h"
#include <cstring>

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    cursos = nullptr;
    numCursos = 0;
}

Alumno::Alumno(const Alumno &al) : Alumno() {
    *this = al;
}

Alumno &Alumno::operator=(const Alumno &al) {
    if (this == &al) return *this;
    setCodigo(al.codigo);
    setNombre(al.nombre);
    setCursos(al.cursos);
    setNumCursos(al.numCursos);
    return *this;
}

Alumno::~Alumno() {
    delete[] nombre;
    if (cursos) {
        for (int i = 0; cursos[i] != nullptr; ++i)
            delete[] cursos[i];
        delete[] cursos;
    }
}

int Alumno::getCodigo() const {
    return codigo;
}
void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

char *Alumno::getNombre() const {
    if (!nombre) return nullptr;
    char *copia = new char[strlen(nombre) + 1];
    strcpy(copia, nombre);
    return copia;
}

void Alumno::setNombre(char *nombre) {
    delete[] this->nombre;
    if (nombre) {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
    } else {
        this->nombre = nullptr;
    }
}

char **Alumno::getCursos() const {
    if (!cursos) return nullptr;
    char **copia = new char *[numCursos + 1];
    for (int i = 0; i < numCursos; ++i) {
        copia[i] = new char[strlen(cursos[i]) + 1];
        strcpy(copia[i], cursos[i]);
    }
    copia[numCursos] = nullptr;
    return copia;
}

void Alumno::setCursos(char **cursos) {
    if (this->cursos) {
        for (int i = 0; this->cursos[i] != nullptr; ++i)
            delete[] this->cursos[i];
        delete[] this->cursos;
    }

    if (cursos) {
        int contador = 0;
        while (cursos[contador] != nullptr) ++contador;
        this->cursos = new char *[contador + 1];
        for (int i = 0; i < contador; ++i) {
            this->cursos[i] = new char[strlen(cursos[i]) + 1];
            strcpy(this->cursos[i], cursos[i]);
        }
        this->cursos[contador] = nullptr;
        this->numCursos = contador;
    } else {
        this->cursos = nullptr;
        this->numCursos = 0;
    }
}

int Alumno::getNumCursos() const {
    return numCursos;
}
void Alumno::setNumCursos(int numCursos) {
    this->numCursos = numCursos;
}

void Alumno::agregarCurso(const char *nuevoCurso) {
    char **nuevoArr = new char *[numCursos + 2];
    for (int i = 0; i < numCursos; ++i) {
        if (cursos) {
            nuevoArr[i] = cursos[i];
        }
        else
            nuevoArr[i] = nullptr;
    }

    nuevoArr[numCursos] = new char[strlen(nuevoCurso) + 1];
    strcpy(nuevoArr[numCursos], nuevoCurso);
    nuevoArr[numCursos + 1] = nullptr;

    if (cursos) delete[] cursos;
    cursos = nuevoArr;
    numCursos++;
}

bool Alumno::estaMatriculado(const char *codigoCurso) const {
    if (!cursos) return false;
    for (int i = 0; i < numCursos; ++i)
        if (strcmp(cursos[i], codigoCurso) == 0)
            return true;
    return false;
}