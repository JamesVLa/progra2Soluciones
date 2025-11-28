//
// Created by james on 28/11/2025.
//

#include "Furgon.h"

Furgon::Furgon() {
    filas=0;
    puertas=0;
}
Furgon::Furgon(const Furgon &furgon) {
    *this=furgon;
}
Furgon &Furgon::operator=(const Furgon &furgon) {
    if (this==&furgon) return *this;
    setFilas(furgon.getFilas());
    setPuertas(furgon.getPuertas());
    pdeposito=furgon.pdeposito;
    return *this;
}

void Furgon::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch >> filas;
    arch.ignore();
    arch >> puertas;
    arch.get();
}

void Furgon::imprime(ofstream &arch) const {
    Vehiculo::imprime(arch);
    arch << left << setw(15) << "#filas:" << right << setw(10) << filas << endl;
    arch << left << setw(15) << "#puertas:" << right << setw(10) << puertas << endl;
    if (pdeposito.size() == 0) {
        arch<<"No hay pedidos para el cliente"<<endl;
    }
    else {
        arch << "Lista de  Pedidos: " << endl;
        for (auto &x:pdeposito) {
            x.imprimir(arch);
        }
    }
}
void Furgon::ingresaPedido(ifstream &arch) {
    NPedido pedido;
    pedido.leer(arch);
    double pesoActual=getActcarga();
    double nuevoPeso=pesoActual+pedido.getPeso();
    if (nuevoPeso<getMaxcarga()) {
        pdeposito.push_front(pedido);
        setActcarga(nuevoPeso);
    }
}

int Furgon::getFilas() const {
    return filas;
}
void Furgon::setFilas(int filas) {
    this->filas=filas;
}
int Furgon::getPuertas() const {
    return puertas;
}
void Furgon::setPuertas(int puertas) {
    this->puertas=puertas;
}


