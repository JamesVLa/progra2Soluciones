//
// Created by james on 21/11/2025.
//

#include "Lista.h"

#include "../src/PedidoEspecial.h"
#include "../src/PedidoEventual.h"
#include "../src/PedidoUsual.h"

Lista::Lista() {
    lini=nullptr;
    lfin=nullptr;
}
// 397718,10,LECHE LALA SEMI DESLACTOSADA 1LT,0,0,46462527,18/10/2019
// 406688,5,10,CHURROMAIS CON LIMON 38GR,9,4.5,32821689,19/10/2021
// Código,descuento y/o flete, nombre, Cantidad, monto del pedido, DNI del cliente,Fecha del pedido.
void Lista::insertar(Pedido *p) {
    Nodo *nuevo=new Nodo;
    nuevo->ped=p;
    if (lini==nullptr) {// CASO 1la lista esta vacia
        lini=lfin=nuevo;
        return;
    }// no esta vacia
    Nodo *aux=lini;

    while (aux!=nullptr && *(aux->ped)<*p) {
        aux=aux->sig;
    }
    if (aux==nullptr) {// CASO 2 SE INSERTA AL FINAL
        nuevo->ant=lfin;
        lfin->sig=nuevo;
        lfin=nuevo;
        return;
    }
    //CASO 3 SE INSERTA AL INICIO
    if (aux==lini) {
        nuevo->sig=lini;
        lini->ant=nuevo;
        lini=nuevo;
        return;
    }
    //CASO 4 SE INSERTA AL MEDIO
    nuevo->sig=aux;
    nuevo->ant=aux->ant;

    aux->ant->sig=nuevo;
    aux->ant=nuevo;

}

void Lista::leePed(ifstream &arch) {
    int codigo;
    Pedido* ped=nullptr;
    while (arch>>codigo) {
        arch.get();
        if (codigo<400000) {
            ped= new PedidoEspecial(codigo);
        }else if (codigo>=400000 and codigo<600000) {
            ped= new PedidoUsual(codigo);
        }else {
            ped = new PedidoEventual(codigo);
        }
        ped->lee(arch);
        insertar(ped);
    }
}

void Lista::imprimePed(ostream &arch) {
    Nodo *aux=lini;
    arch<<fixed;
    arch.precision(2);
    while (aux!=nullptr) {
        aux->ped->imprime(arch);
        arch<<endl;
        aux=aux->sig;
    }
}

void Lista::actualiza(int dni, int fecha) {

}

Lista::~Lista() {

}
