//
// Created by james on 27/11/2025.
//

#include "Infraccion.h"

Infraccion::Infraccion() {

}

Infraccion::Infraccion(const Infraccion &orig) {
    *this=orig;
}

Infraccion &Infraccion::operator=(const Infraccion &orig) {
    if (this==&orig)return *this;
    setCodigo(orig.getCodigo());
    setMulta(orig.getMulta());
    setGravedad(orig.getGravedad());
    setDescripcion(orig.getDescripcion());
    return *this;
}

// M1046,658.70, Muy grave,Obstruir la ciclovia
// G2030,433.12, Leve,Circular en forma desordenada o haciendo maniobras peligrosas
// Contenido: Código de la infracción, multa, gravedad y descripción de la infracción

void Infraccion::leer(ifstream &arch) {
    getline(arch,codigo,',');
    if (arch.eof())return;
    arch>>multa;
    arch.ignore();
    getline(arch,gravedad,',');
    getline(arch,descripcion);
}

void Infraccion::imprimir(ofstream &arch) {
    arch<<codigo<<" "<<multa<<" "<<gravedad<<" "<<descripcion<<endl;
}

bool Infraccion::operator<(const Infraccion &orig) {
    return getCodigo()<orig.getCodigo();
}

ifstream &operator>>(ifstream &arch, Infraccion &infra) {
    infra.leer(arch);
    return arch;
}
ofstream &operator<<(ofstream &arch,Infraccion &infra) {
    infra.imprimir(arch);
    return arch;
}

string Infraccion::getCodigo() const {
    return codigo;
}
void Infraccion::setCodigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::getMulta() const {
    return multa;
}
void Infraccion::setMulta(double multa) {
    this->multa = multa;
}

string Infraccion::getGravedad() const {
    return gravedad;
}
void Infraccion::setGravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::getDescripcion() const {
    return descripcion;
}
void Infraccion::setDescripcion(const string &descripcion) {
    this->descripcion = descripcion;
}
