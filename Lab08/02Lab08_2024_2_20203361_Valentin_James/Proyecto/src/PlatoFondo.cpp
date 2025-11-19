//
// Created by james on 13/11/2025.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = 0;
}
PlatoFondo::PlatoFondo(const PlatoFondo &origen):PlatoFondo() {
    *this = origen;
}
PlatoFondo &PlatoFondo::operator=(const PlatoFondo &origen) {
    if (this==&origen) return *this;
    Producto::operator=(origen);
    setProteina(origen.getProteina());
    return *this;
}
void PlatoFondo::lee(ifstream &arch) {
    Producto::lee(arch);
    arch>>proteina;
    arch.get();
}

void PlatoFondo::imprime(ostream& arch){
    Producto::imprime(arch);
    arch<<"Proteina: ";
    switch (proteina) {
        case 1:
            arch<<"Pollo";
            break;
        case 2:
            arch<<"Carne";
            break;
        case 3:
            arch<<"Pescado";
            break;
        case 4:
            arch<<"Lácteos";
            break;
        default:
            arch<<"No reconocida";
            break;
    }
    arch<<endl;
}

void PlatoFondo::setProteina(int proteina) {
    this->proteina=proteina;
}
int PlatoFondo::getProteina() const {
    return proteina;
}

Producto *PlatoFondo::clone() const {
    return new PlatoFondo(*this);
}

bool PlatoFondo::validar(int num) const {
    if (proteina==num) {
        return true;
    }
    return false;
}



