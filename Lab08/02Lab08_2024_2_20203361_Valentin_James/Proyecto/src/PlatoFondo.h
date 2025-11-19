//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_PLATOFONDO_H
#define PROYECTO_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo:public Producto{
    int proteina;
public:
    PlatoFondo();
    PlatoFondo(const PlatoFondo& origen);
    PlatoFondo& operator=(const PlatoFondo& origen);
    void lee(ifstream& arch) override;
    void imprime(ostream& arch) override;
    ~PlatoFondo()=default;
    int getProteina() const;
    void setProteina(int proteina);
    bool validar(int num)const override;
    Producto* clone() const override;
};


#endif //PROYECTO_PLATOFONDO_H