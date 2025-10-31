//
// Created by james on 28/10/2025.
//

#include "Multa.h"

#include <cstring>
Multa::Multa() {
    this->placa=nullptr;
    this->fechaDeInfraccion=0;
    this->fechaDePago=0;
    this->codigoInfraccion=0;
    this->multa=0.0;
}

Multa::Multa(const Multa &origen):Multa() {
    *this=origen;
}
Multa::~Multa() {
    delete [] this->placa;
}
Multa &Multa::operator=(const Multa &origen) {
    if (this == &origen)return *this;
    this->setPlaca(origen.getPlaca());
    this->setFechaDeInfraccion(origen.getFechaDeInfraccion());
    this->setFechaDePago(origen.getFechaDePago());
    this->setCodigoInfraccion(origen.getCodigoInfraccion());
    this->setMulta(origen.getMulta());
    return *this;
}
void Multa::copiarCadena(char *&destino, const char *origen) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    } else {
        destino = nullptr;
    }
}
void Multa::setPlaca(char *placa) {
    copiarCadena(this->placa, placa);
}
char *Multa::getPlaca() const {
    return this->placa;
}

void Multa::setFechaDeInfraccion(int fechaDeInfraccion) {
    this->fechaDeInfraccion=fechaDeInfraccion;
}
int Multa::getFechaDeInfraccion() const {
    return this->fechaDeInfraccion;
}

void Multa::setFechaDePago(int fechaDePago) {
    this->fechaDePago=fechaDePago;
}
int Multa::getFechaDePago() const {
    return this->fechaDePago;
}

void Multa::setCodigoInfraccion(int codigoInfraccion) {
    this->codigoInfraccion=codigoInfraccion;
}
int Multa::getCodigoInfraccion() const {
    return this->codigoInfraccion;
}

void Multa::setMulta(double multa) {
    this->multa=multa;
}
double Multa::getMulta() const {
    return this->multa;
}

//