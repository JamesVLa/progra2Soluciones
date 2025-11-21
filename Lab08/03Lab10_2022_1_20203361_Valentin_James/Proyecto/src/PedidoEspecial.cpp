//
// Created by james on 21/11/2025.
//

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento = 0.0;
}

PedidoEspecial::PedidoEspecial(int codigo):PedidoEspecial() {
    setCodigo(codigo);
}
PedidoEspecial::PedidoEspecial(const PedidoEspecial &orig):PedidoEspecial() {
    *this = orig;
}

PedidoEspecial &PedidoEspecial::operator=(const PedidoEspecial &orig) {
    if (this == &orig) return *this;
    Pedido::operator=(orig);
    setDescuento(orig.getDescuento());
    return *this;
}

void PedidoEspecial::lee(ifstream &arch) {
    arch>>descuento;
    arch.ignore();
    Pedido::lee(arch);
}
void PedidoEspecial::imprime(ostream &arch) {
    Pedido::imprime(arch);
    arch<<"Descuento: "<<descuento<<endl;
}

void PedidoEspecial::setDescuento(double descuento) {
    this->descuento=descuento;
}
double PedidoEspecial::getDescuento()const {
    return this->descuento;
}





