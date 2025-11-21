//
// Created by james on 21/11/2025.
//

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
    descuento = 0.0;
    flete = 0.0;
}

PedidoUsual::PedidoUsual(const PedidoUsual &orig) {
    *this = orig;
}
PedidoUsual::PedidoUsual(int codigo):PedidoUsual() {
    setCodigo(codigo);
}

PedidoUsual &PedidoUsual::operator=(const PedidoUsual &orig) {
    if (this==&orig)return *this;
    Pedido::operator=(orig);
    setDescuento(orig.getDescuento());
    setFlete(orig.getFlete());
    return *this;
}

void PedidoUsual::lee(ifstream &arch) {
    arch>>descuento;
    arch.ignore();
    arch>>flete;
    arch.ignore();
    Pedido::lee(arch);
}

void PedidoUsual::imprime(ostream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento: "<<descuento<<endl;
    arch<<"Flete: "<<flete<<endl;
}

double PedidoUsual::getDescuento()const {
    return descuento;
}
double PedidoUsual::getFlete() const {
    return flete;
}
void PedidoUsual::setFlete(double flet) {
    this->flete = flet;
}
void PedidoUsual::setDescuento(double descuento) {
    this->descuento=descuento;
}



