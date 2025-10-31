//
// Created by james on 28/10/2025.
//

#include "Infraccion.h"
#include <cstring>

Infraccion::Infraccion() {
    this->codigo = 0;
    this->descripcion = nullptr;
    this->gravedad = nullptr;
    this->multa = 0.0;
}

Infraccion::Infraccion(const Infraccion & origen):Infraccion() {
    *this = origen;
}

Infraccion::~Infraccion() {
    delete [] this->descripcion;
    delete [] this->gravedad;
}

Infraccion &Infraccion::operator=(const Infraccion & origen) {
    if (this == &origen) return *this;
    this->setCodigo(origen.getCodigo());
    this->setDescripcion(origen.getDescripcion());
    this->setGravedad(origen.getGravedad());
    this->setMulta(origen.getMulta());
    return *this;
}

void Infraccion::copiarCadena(char *&destino, const char *origen) {
    delete[] destino;// con [] o sin []
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    } else {
        destino = nullptr;
    }
}

void Infraccion::setCodigo(int codigo) {
    this->codigo = codigo;
}
int Infraccion::getCodigo() const {
    return codigo;
}

void Infraccion::setDescripcion(char *descripcion) {
    copiarCadena(this->descripcion, descripcion);
}
char *Infraccion::getDescripcion() const {
    return descripcion;
}

void Infraccion::setGravedad(char *gravedad) {
    copiarCadena(this->gravedad, gravedad);
}
char *Infraccion::getGravedad() const {
    return gravedad;
}

void Infraccion::setMulta(double multa) {
    this->multa = multa;
}
double Infraccion::getMulta() const {
    return multa;
}

//
