//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_CAMION_H
#define PROYECTO_CAMION_H
#include "NPedido.h"
#include "Utils.h"
#include "Vehiculo.h"

class Camion :public Vehiculo {
private:
    int ejes;
    int llantas;
    map<int,NPedido> mdeposito;
    public:
    Camion();
    Camion(const Camion& camion);
    Camion& operator=(const Camion& camion);
    ~Camion()=default;
    void lee(ifstream &arch)override;
    void imprime(ofstream &arch) const override;
    void ingresaPedido(ifstream &arch) override;
    int getEjes() const;
    void setEjes( int ejes);

    int getLlantas() const;
    void setLlantas( int llantas);
};


#endif //PROYECTO_CAMION_H