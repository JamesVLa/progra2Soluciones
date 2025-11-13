//
// Created by james on 12/11/2025.
//

#include "Dron.h"

Dron::Dron() {
    id=nullptr;
    ubicacion=nullptr;
    capacidad=0;
}

Dron::Dron(const Dron &dron):Dron(){
    *this=dron;
}

Dron &Dron::operator=(const Dron &dron) {
    if (this==&dron)return *this;
    this->setId(dron.getId());
    this->setUbicacion(dron.getUbicacion());
    this->setCapacidad(dron.getCapacidad());
    return *this;
}

Dron::~Dron() {
    liberarCadena(this->id);
    liberarCadena(this->ubicacion);
}
const char *Dron::getId() const{
    return this->id;
}
const char *Dron::getUbicacion() const{
    return this->ubicacion;
}

int Dron::getCapacidad() const{
    return capacidad;
}
void Dron::setCapacidad(int capacidad) {
    this->capacidad=capacidad;
}
void Dron::setId(const char *id) {
    liberarCadena(this->id);
    this->id=miString(id);
}

void Dron::setUbicacion(const char *ubicacion) {
    liberarCadena(this->ubicacion);
    this->ubicacion=miString(ubicacion);
}



void Dron::lee(ifstream &arch) {
    char aux[50];
    arch.getline(aux,50,',');
    setId(aux);
    arch.getline(aux,50,',');
    setUbicacion(aux);
    arch>>capacidad;
    arch.get();
}

bool Dron::operator>(const Dron &dron) const {
    if (strcmp(this->id,dron.getId())>0) {
        return true;
    }
    return false;
}

void Dron::imprime(ofstream &arch) const {
    arch<<setw(10)<<" "<<left<<this->id<<setw(15)<<this->ubicacion<<setw(15)<<this->capacidad;
    // arch<<setw(10)<<" "<<left<<setw(10)<<this->getId()
    // <<setw(15)<<this->getUbicacion()
    // <<setw(15)<<this->getCapacidad();
}



