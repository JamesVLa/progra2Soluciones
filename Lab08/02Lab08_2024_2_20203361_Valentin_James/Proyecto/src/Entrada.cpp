//
// Created by james on 13/11/2025.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante=false;
}

Entrada::Entrada(const Entrada &origen):Entrada() {
    *this = origen;
}

Entrada &Entrada::operator=(const Entrada &origen) {
    if (this == &origen)return *this;
    Producto::operator=(origen);
    setPicante(origen.isPicante());
    return *this;
}

void Entrada::lee(ifstream &arch) {
    Producto::lee(arch);
    char pic[50];
    arch.getline(pic,50,'\n');
    if (strcmp(pic,"picante")==0) {
        setPicante(true);
    }else {
        setPicante(false);
    }
}

void Entrada::imprime(ostream &arch) {
    Producto::imprime(arch);
    if (isPicante()) {
        arch<<"Picante";
    }else{
        arch<<"Sin Picante";
    }
    arch<<endl;
}

bool Entrada::isPicante() const {
    return picante;
}

void Entrada::setPicante(bool picante) {
    this->picante = picante;
}

Producto *Entrada::clone() const {
    return new Entrada(*this);
}

bool Entrada::validar(int num) const {
    return false;
}
