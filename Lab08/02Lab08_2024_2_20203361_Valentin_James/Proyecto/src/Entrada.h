//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_ENTRADA_H
#define PROYECTO_ENTRADA_H
#include "Producto.h"


class Entrada:public Producto{
    bool picante;

public:
    Entrada();
    Entrada(const Entrada& origen);
    Entrada& operator=(const Entrada& origen);
    void lee(ifstream& arch) override;
    void imprime(ostream &arch) override;
    ~Entrada()=default;
    bool isPicante() const;
    void setPicante(bool picante);
    bool validar(int num)const override;
    Producto* clone() const override;
};


#endif //PROYECTO_ENTRADA_H