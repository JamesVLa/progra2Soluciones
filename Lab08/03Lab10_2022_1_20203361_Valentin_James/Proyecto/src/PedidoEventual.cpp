//
// Created by james on 21/11/2025.
//

#include "PedidoEventual.h"

#include "Pedido.h"


PedidoEventual::PedidoEventual() {
    this->flete=0.0;
}
PedidoEventual::PedidoEventual(const PedidoEventual &orig):PedidoEventual() {
    *this = orig;
}
PedidoEventual::PedidoEventual(int codigo):Pedido() {
    setCodigo(codigo);
}

void PedidoEventual::lee(ifstream &arch) {
    arch>>flete;
    arch.ignore();
    Pedido::lee(arch);
}
void PedidoEventual::imprime(ostream &arch) {
    Pedido::imprime(arch);
    arch<<"Flete: "<<flete<<endl;
}

PedidoEventual &PedidoEventual::operator=(const PedidoEventual &orig) {
    if (this==&orig)return *this;
    Pedido::operator=(orig);
    setFlete(orig.getFlete());
    return *this;
}

double PedidoEventual::getFlete() const {
    return flete;
}

void PedidoEventual::setFlete(double flete) {
    this->flete=flete;
}


