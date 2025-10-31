//
// Created by james on 30/10/2025.
//

#include "Infraccion.h"

#include <cstring>


Infraccion::Infraccion() {
    codigo=0;
    descripcion=nullptr;
    gravedad=nullptr;
    multa=0.0;
}

Infraccion::Infraccion(const Infraccion & origen):Infraccion() {
    *this = origen;
}

Infraccion::~Infraccion() {
    delete []descripcion;
    delete []gravedad;
}

Infraccion& Infraccion::operator=(const Infraccion & origen) {
    if (this == &origen) return *this;
    this->setCodigo(origen.getCodigo());
    this->setDescripcion(origen.getDescripcion());
    this->setGravedad(origen.getGravedad());
    this->setMulta(origen.getMulta());
    return *this;
}

//setters
void Infraccion::setCodigo(int codigo) {
    this->codigo=codigo;
}
void Infraccion::setDescripcion(char *descripcion) {
    delete []this->descripcion;
    if (descripcion) {
        this->descripcion=new char[strlen(descripcion)+1];
        strcpy(this->descripcion,descripcion);
    }else {
        this->descripcion=nullptr;
    }
}
void Infraccion::setGravedad(char *gravedad) {
    delete []this->gravedad;
    if (gravedad) {
        this->gravedad=new char[strlen(gravedad)+1];
        strcpy(this->gravedad,gravedad);
    }else {
        this->gravedad=nullptr;
    }
}
void Infraccion::setMulta(double multa) {
    this->multa=multa;
}
//Getters
int Infraccion::getCodigo()const {
    return this->codigo;
}
char* Infraccion::getDescripcion()const{
    return this->descripcion;
}
char* Infraccion::getGravedad()const {
    return this->gravedad;
}
double Infraccion::getMulta()const {
    return this->multa;
}

// 2007,425.23,Grave,No conducir por
istream & operator>>(istream& arch, Infraccion& inf) {
    int codigo;
    double multa;
    char buff[200];
    arch>>codigo;
    if (arch.eof())return arch;
    inf.setCodigo(codigo);
    arch.ignore();
    arch>>multa;
    inf.setMulta(multa);
    arch.ignore();
    arch.getline(buff,200,',');
    inf.setGravedad(buff);
    arch.getline(buff,200);
    inf.setDescripcion(buff);
    return arch;
}

ostream & operator<<(ostream& arch, const Infraccion& inf) {
    return arch;
}