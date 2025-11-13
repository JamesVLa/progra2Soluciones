//
// Created by james on 12/11/2025.
//

#include "Arbol.h"

#include "../src/DroneEstacionamiento.h"
#include "../src/DroneSemaforo.h"
#include "../src/DroneVelocidad.h"

Arbol::Arbol() {
    this->raiz=nullptr;
}
Arbol::~Arbol() {
    delete this->raiz;
}

void Arbol::lee(ifstream &arch) {
    Dron *aux;

    char tipo[100];
    arch.getline(tipo, 100,',');
    if (arch.eof())return;
    if (strcmp(tipo, "Velocidad")==0) {
        aux=new DroneVelocidad();
    }else if (strcmp(tipo, "Semaforo")==0) {
        aux=new DroneSemaforo();
    }else {
        aux=new DroneEstacionamiento();
    }
    aux->lee(arch);
    insertar(aux);
}

void Arbol::imprimir(ofstream &arch)const {
    imprimirR(arch,this->raiz);
}

void Arbol::imprimirR(ofstream &arch, Nodo *nodoImp) const {
    if (nodoImp!=nullptr) {
        imprimirR(arch,nodoImp->izq);
        nodoImp->dron->imprime(arch);
        imprimirR(arch,nodoImp->der);
    }
}

void Arbol::insertar(Dron *aux) {
    insertarR(this->raiz,aux);
}

void Arbol::insertarR(Nodo *&nodoIns, Dron *aux) {
    //Caso Base
    if (nodoIns==nullptr) {
        nodoIns=new Nodo();
        nodoIns->dron=aux;
    }else if (*(nodoIns->dron)>(*aux)){
        insertarR(nodoIns->izq,aux);
    }else {
        insertarR(nodoIns->der,aux);
    }
}

void Arbol::actualiza() {
    int numSemaf=0,numEstac=0;
    contarR(this->raiz,numSemaf,numEstac);
    numSemaf=numSemaf/2;
    numEstac=numEstac/2;
    actualizarR(this->raiz,numSemaf,numEstac);
}

void Arbol::contarR(Nodo *nodoEv, int &numSemaf, int &numEstac)const {
    const char *tipo;

    if (nodoEv!=nullptr) {
        contarR(nodoEv->izq,numSemaf,numEstac);
        tipo=nodoEv->dron->getId();
        if (tipo[1]=='S')numSemaf++;
        else if (tipo[1]=='E')numEstac++;
        contarR(nodoEv->der,numSemaf,numEstac);
    }

}

void Arbol::actualizarR(Nodo *nodoEv, int &numSemaf, int &numEstac) const {
    const char *tipo;
    if (nodoEv!=nullptr) {
        actualizarR(nodoEv->izq,numSemaf,numEstac);
        tipo=nodoEv->dron->getId();
        if (tipo[1]=='S' and numSemaf>0) {
            nodoEv->dron->actualiza();
            numSemaf--;
        }
        else if (tipo[1]=='E' and numEstac>0){
            nodoEv->dron->actualiza();
            numEstac--;
        }
        actualizarR(nodoEv->der,numSemaf,numEstac);
    }
}
