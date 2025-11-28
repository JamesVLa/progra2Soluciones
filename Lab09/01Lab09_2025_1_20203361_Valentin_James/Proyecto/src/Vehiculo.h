//
// Created by james on 27/11/2025.
//

#ifndef PROYECTO_VEHICULO_H
#define PROYECTO_VEHICULO_H
// JAMES VALENTIN 20203361
#include "Utils.h"

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    public:
    Vehiculo()=default;
    Vehiculo(const Vehiculo &orig);
    Vehiculo & operator=(const Vehiculo &orig);

    void leer(ifstream &arch);
    void imprime(ofstream &arch)const ;
    string getPlaca() const;
    void setPlaca(const string &placa);

    string getMarca() const;
    void setMarca(const string &marca);

    string getModelo() const;
    void setModelo(const string &modelo);

};

ifstream &operator>>(ifstream &input, Vehiculo &v);
ofstream &operator<<(ofstream &output, const Vehiculo &v);


#endif //PROYECTO_VEHICULO_H
