//
// Created by james on 28/10/2025.
//

#include "Empresa.h"
#include <cstring>

Empresa::Empresa() {
    this->dni=0;
    this->nombre=nullptr;
    for (int i = 0; i < 10; i++)this->placas[i] = nullptr;
    this->numPlacas=0;
    this->numMultas=0;
    // for (int i = 0; i < 100; i++) multas[i] = Multa(); Este ya no
}
Empresa::Empresa(const Empresa &origen) {
    *this=origen;
}

Empresa& Empresa::operator=(const Empresa& origen) {
    if (this == &origen)return *this;
    setDni(origen.getDni());
    this->setNombre(origen.getNombre());
    for (int i = 0; i < origen.getNumPlacas(); i++)setPlacaI(origen.getPlacaI(i),i);
    this->setNumPlacas(origen.getNumPlacas());
    this->setNumMultas(origen.getNumMultas());
    for (int i = 0; i < origen.getNumMultas(); i++) {
        this->multas[i] = origen.multas[i];
    }
    return *this;
}
Empresa::~Empresa() {
    delete[] this->nombre;
    for (int i = 0; i < 10; i++)delete[] placas[i];
}
void Empresa::copiarCadena(char *&destino, const char *origen) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    } else {
        destino = nullptr;
    }
}

void Empresa::setDni(int dni) {
    this->dni = dni;
}
int Empresa::getDni() const {
    return dni;
}

void Empresa::setNombre(char * nombre) {
    copiarCadena(this->nombre, nombre);
}
char * Empresa::getNombre() const {
    return nombre;
}

// void Empresa::getNombre(char* nomb) const {
//     if (nombre == nullptr) nomb[0] = 0;
//     else strcpy(nomb,nombre);
// }

void Empresa::setPlacaI( char *placa, int i) {
    copiarCadena(this->placas[i], placa);
}
char* Empresa::getPlacaI(int i) const {
    return this->placas[i];
}

// void Empresa::get_placaI(char *pl, int i) const {
//     if (placas[i]==nullptr) pl[0] = 0;
//     else strcpy(pl,placas[i]);
// }
void Empresa::setNumPlacas(int numPlacas) {
    this->numPlacas = numPlacas;
}
int Empresa::getNumPlacas() const {
    return numPlacas;
}

void Empresa::setNumMultas( int numMultas) {
    this->numMultas = numMultas;
}
int Empresa::getNumMultas() const {
    return numMultas;
}

void Empresa::agregarPlaca(char *placa) {
    if (numPlacas<10 && placa) {
        setPlacaI(placa,numPlacas);
        numPlacas++;
    }
}
void Empresa::agregarMulta(Multa &m) {// o const Multa??
    if (numMultas < 100) {
        multas[numMultas] = m;
        numMultas++;
    }
}