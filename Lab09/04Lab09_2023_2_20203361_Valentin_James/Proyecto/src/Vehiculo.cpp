//
// Created by james on 28/11/2025.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    cliente=0;
    maxcarga=0;
    actcarga=0;
}
Vehiculo::Vehiculo(const Vehiculo &v):Vehiculo() {
    *this=v;
}

Vehiculo &Vehiculo::operator=(const Vehiculo &v) {
    if (this==&v) return *this;
    setCliente( v.getCliente() );
    setPlaca( v.getPlaca() );
    setMaxcarga( v.getMaxcarga() );
    setActcarga( v.getActcarga() );
    return *this;
}

void Vehiculo::lee(ifstream &arch) {
    arch>>cliente;
    arch.ignore();
    getline(arch,placa,',');
    arch>>maxcarga;
    arch.ignore();
}
void Vehiculo::imprime(ofstream &arch) const {
    arch<<left<<setw(15)<<"Codigo Cliente: "<<right<<setw(10)<<cliente<<endl;
    arch<<left<<setw(15)<<"Placa: "<<right<<setw(10)<<placa<<endl;
    arch<<left<<setw(15)<<"Carga Maxima: "<<right<<setw(10)<<maxcarga<<endl;
    arch<<left<<setw(15)<<"Carga Actual: "<<right<<setw(10)<<actcarga<<endl;
}
int Vehiculo::getCliente() const {
    return cliente;
}

void Vehiculo::setCliente( int cliente) {
    this->cliente = cliente;
}

string Vehiculo::getPlaca() const {
    return placa;
}

void Vehiculo::setPlaca(const string &placa) {
    this->placa = placa;
}

double Vehiculo::getMaxcarga() const {
    return maxcarga;
}

void Vehiculo::setMaxcarga( double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::getActcarga() const {
    return actcarga;
}

void Vehiculo::setActcarga( double actcarga) {
    this->actcarga = actcarga;
}
