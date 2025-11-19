//
// Created by james on 13/11/2025.
//

#include "DetalleComanda.h"

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

DetalleComanda::DetalleComanda() {
    id=0;
    pedido=nullptr;
}

DetalleComanda::DetalleComanda(const DetalleComanda &orig):DetalleComanda() {
    *this=orig;
}
DetalleComanda &DetalleComanda::operator=(const DetalleComanda &orig) {
    if (this==&orig)return *this;
    setId(orig.getId());
    if (orig.pedido==nullptr) {
        pedido=nullptr;
    }
    else {
        // pedido=orig.pedido;
        pedido=orig.pedido->clone();
    }
    return *this;
}
DetalleComanda::~DetalleComanda() {
    delete pedido;
}

void DetalleComanda::leer(ifstream &arch) {
    int id;
    char tipo;
    arch >> id;
    if (arch.eof()) return;
    setId(id);
    arch.ignore();
    arch >> tipo;
    arch.ignore();
    switch (tipo) {
        case 'B':
            pedido=new Bebida;
            break;
        case 'E':
            pedido=new Entrada;
            break;
        case 'P':
            pedido=new PlatoFondo;
            break;
    }
    pedido->lee(arch);
}

void DetalleComanda::imprimir(ostream &arch) {
    arch<<fixed<<setprecision(2);
    arch<<"Codigo de comanda: "<<id<<endl;
    pedido->imprime(arch);
    arch<<endl;
}

void DetalleComanda::setId(int id) {
    this->id=id;
}
int DetalleComanda::getId() const {
    return id;
}

bool DetalleComanda::validar(int num) {
    return pedido->validar(num);
}



