//
// Created by james on 27/11/2025.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo(const Vehiculo &orig) {
    *this = orig;
}

Vehiculo &Vehiculo::operator=(const Vehiculo &orig) {
    if (this==&orig)return *this;
    setPlaca(orig.getPlaca());
    setModelo(orig.getMarca());
    setModelo(orig.getModelo());
    return *this;
}

string Vehiculo::getPlaca() const {
    return placa;
}

void Vehiculo::setPlaca(const string &placa) {
    this->placa = placa;
}

string Vehiculo::getMarca() const {
    return marca;
}

void Vehiculo::setMarca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::getModelo() const {
    return modelo;
}

void Vehiculo::setModelo(const string &modelo) {
    this->modelo = modelo;
}

void Vehiculo::leer(ifstream &arch) {
    getline(arch, placa,',');
    if (arch.eof())return;
    getline(arch, marca,',');
    getline(arch, modelo);
}

void Vehiculo::imprime(ofstream &arch) const{

}

ifstream &operator>>(ifstream &input, Vehiculo &v) {
    v.leer(input);
    return input;
}

ofstream &operator<<(ofstream &output, const Vehiculo &v) {
    v.imprime(output);
    return output;
}
