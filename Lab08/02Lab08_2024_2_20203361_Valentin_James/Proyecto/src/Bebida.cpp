//
// Created by james on 13/11/2025.
//

#include "Bebida.h"

Bebida::Bebida() {
    tamano = 0;
}

Bebida::~Bebida() {
    liberarCadena(tamano);
}
Bebida::Bebida(const Bebida &b):Bebida() {
    *this = b;
}
void Bebida::lee(ifstream &arch) {
    Producto::lee(arch);
    char tam[50];
    arch.getline(tam,50,'\n');
    setTamano(tam);
}
void Bebida::imprime(ostream &arch) {
    Producto::imprime(arch);
    arch <<"Tamano: "<<tamano<<endl;
}

Bebida& Bebida::operator=(const Bebida& origen) {
    if (this==&origen)return *this;
    Producto::operator=(origen);
    char cadena[50];
    origen.getTamano(cadena);
    setTamano(cadena);
    return *this;
}
void Bebida::getTamano(char *tamano) const {
    if (this->tamano==nullptr)tamano[0]=0;
    else strcpy(tamano,this->tamano);
}

void Bebida::setTamano(const char *tamano) {
    liberarCadena(this->tamano);
    this->tamano = miString(tamano);
}
Producto *Bebida::clone() const {
    return new Bebida(*this);
}

bool Bebida::validar(int num) const {
    return false;
}
