//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_FURGON_H
#define PROYECTO_FURGON_H

#include "NPedido.h"
#include "Utils.h"
#include "Vehiculo.h"

class Furgon :public Vehiculo{
    int filas;
    int puertas;
    list<NPedido> pdeposito;
public:
    Furgon();
    Furgon(const Furgon& furgon);
    Furgon& operator=(const Furgon& furgon);
    void lee(ifstream &arch)override;
    void imprime(ofstream &arch) const override;
    void ingresaPedido(ifstream &arch) override;
    ~Furgon()=default;
    int getFilas() const;
    void setFilas( int filas);

    int getPuertas() const;
    void setPuertas( int puertas);
};


#endif //PROYECTO_FURGON_H