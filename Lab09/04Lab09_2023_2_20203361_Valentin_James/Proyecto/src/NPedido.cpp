//
// Created by james on 28/11/2025.
//

#include "NPedido.h"



NPedido::NPedido() {
    cantidad=0;
    peso=0.0;
}

NPedido::NPedido(const NPedido &p):NPedido() {
    *this=p;
}
NPedido &NPedido::operator=(const NPedido &p) {
    if (this==&p) return *this;
    setCodigo(p.getCodigo());
    setCantidad(p.getCantidad());
    setPeso(p.getPeso());
    return *this;
}
// 42157219,OTS.581,5,2.5
// 13245501,AWB.345,1,3
// …
// Cliente, Cod del Producto, cantidad, peso del pedido.
void NPedido::leer(ifstream &arch) {
    getline(arch,codigo,',');
    arch>>cantidad;
    arch.ignore();
    arch>>peso;
    arch.get();
}

void NPedido::imprimir(ofstream &arch) const {
    arch<<setw(5)<<" "<<left<<setw(15)<<codigo
    <<setw(10)<<cantidad
    <<setw(10)<<right<<peso<<endl;
}


string NPedido::getCodigo() const {
    return codigo;
}

void NPedido::setCodigo(const string &codigo) {
    this->codigo = codigo;
}

int NPedido::getCantidad() const {
    return cantidad;
}

void NPedido::setCantidad( int cantidad) {
    this->cantidad = cantidad;
}

double NPedido::getPeso() const {
    return peso;
}

void NPedido::setPeso( double peso) {
    this->peso = peso;
}