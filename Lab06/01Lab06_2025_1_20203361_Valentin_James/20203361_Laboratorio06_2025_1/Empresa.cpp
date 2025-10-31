//
// Created by james on 30/10/2025.
//

#include "Empresa.h"

#include <cstring>

Empresa::Empresa() {
    dni=0;
    nombre=nullptr;
    for (int i=0;i<10;i++)placas[i]=nullptr;
    numPlacas=0;
    numMultas=0;
}
Empresa::Empresa(const Empresa &origen):Empresa() {
    *this=origen;
}
Empresa& Empresa::operator=(const Empresa& origen) {
    if (this == &origen)return *this;
    setDni(origen.getDni());
    setNombre(origen.getNombre());
    for (int i=0;i<10;i++)setPlacaI(origen.getPlacaI(i),i);
    setNumPlacas(origen.getNumPlacas());
    for (int i=0;i<numMultas;i++)multas[i]=origen.multas[i];
    setNumMultas(origen.getNumMultas());
    return *this;
}

Empresa::~Empresa() {
    delete [] nombre;
    for (int i=0;i<10;i++)delete []placas[i];
}

//Setters
void Empresa::setDni(int dni) {
    this->dni=dni;
}
void Empresa::setNombre(const char* nombre) {
    delete [] this->nombre;
    if (nombre) {
        this->nombre=new char[strlen(nombre)+1];
        strcpy(this->nombre,nombre);
    }else {
        this->nombre=nullptr;
    }
}
void Empresa::setPlacaI(const char*placa, int i) {
    delete [] this->placas[i];
    if (placa) {
        this->placas[i]=new char[strlen(placa)+1];
        strcpy(this->placas[i],placa);
    }else {
        this->placas[i]=nullptr;
    }
}
void Empresa::setNumPlacas(int numPlacas) {
    this->numPlacas=numPlacas;
}
void Empresa::setNumMultas(int numMultas) {
    this->numMultas=numMultas;
}
//Getters
int Empresa::getDni() const {
    return dni;
}
char* Empresa::getNombre() const {
    return nombre;
}
char* Empresa::getPlacaI(int i) const {
    return placas[i];
}
int Empresa::getNumPlacas() const {
    return numPlacas;
}
int Empresa::getNumMultas() const {
    return numMultas;
}
// int dni;
// char* nombre;
// char *placas[10];
// int numPlacas;
// Multa multas[100];
// int numMultas;
// 13219606,Rodriguez Moreno Blanca Ofelia,P201-291,M312-270,M312-270
// 75348522,Lozada Forzani Delia,G113-951,G841-644,P310-575,G938-356,G744-786
// DNI y nombre del dueño de la empresa,placas de los vehículos de propiedad de la empresa.
istream& operator>>(istream &arch, Empresa &empresa) {
    int dni,numPla=0;
    char buff[200];
    arch>>dni;
    if (arch.eof())return arch;
    empresa.setDni(dni);
    arch.ignore();
    arch.getline(buff,200,',');
    empresa.setNombre(buff);
    while (true) {
        arch.get(buff,9);
        empresa.setPlacaI(buff,numPla);
        numPla++;
        if (arch.get()=='\n')break;
    }
    empresa.setNumPlacas(numPla);
    return arch;
}
ostream& operator<<(ostream &arch, const Empresa &empresa) {

    return arch;
}