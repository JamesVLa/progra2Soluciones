//
// Created by james on 28/11/2025.
//

#include "Camion.h"

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}
Camion::Camion(const Camion &camion):Camion() {
    *this = camion;
}
Camion &Camion::operator=(const Camion &camion) {
    if (this == &camion) return *this;
    setEjes(camion.getEjes());
    setLlantas(camion.getLlantas());
    mdeposito = camion.mdeposito;
    return *this;
}

void Camion::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch >> ejes;
    arch.ignore();
    arch >> llantas;
    arch.get();
}
void Camion::imprime(ofstream &arch) const {
    Vehiculo::imprime(arch);
    arch << left << setw(15) << "#Ejes:" << right << setw(10) << ejes << endl;
    arch << left << setw(15) << "#Llantas:" << right << setw(10) << llantas << endl;
    if (mdeposito.size() == 0) {
        arch<<"No hay pedidos para el cliente"<<endl;
    }
    else {
        arch << "Lista de  Pedidos: " << endl;
        for (auto &x:mdeposito) {
            arch<<right<<setw(5)<<x.first;
            x.second.imprimir(arch);
        }
    }
}

void Camion::ingresaPedido(ifstream &arch) {
    NPedido pedido;
    pedido.leer(arch);
    double pesoActual=getActcarga();
    double nuevoPeso=pesoActual+pedido.getPeso();
    if (mdeposito.size() <5 and nuevoPeso<getMaxcarga()) {
        int key= mdeposito.size()+1;
        mdeposito[key] = pedido;
        setActcarga(nuevoPeso);
    }
}

int Camion::getEjes() const {
    return ejes;
}

void Camion::setEjes(const int ejes) {
    this->ejes = ejes;
}

int Camion::getLlantas() const {
    return llantas;
}

void Camion::setLlantas(const int llantas) {
    this->llantas = llantas;
}
