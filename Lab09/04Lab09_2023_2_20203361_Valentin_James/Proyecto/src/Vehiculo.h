//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_VEHICULO_H
#define PROYECTO_VEHICULO_H
#include "Utils.h"

class Vehiculo {
private:
    int cliente;
    string placa;
    double maxcarga;
    double actcarga;
    public:
    Vehiculo();
    Vehiculo(const Vehiculo &v);
    Vehiculo& operator=(const Vehiculo &v);
    virtual ~Vehiculo()=default;
    virtual void ingresaPedido(ifstream &arch)=0;
    virtual void lee(ifstream& arch);
    virtual void imprime(ofstream& arch)const;
    int getCliente() const;
    void setCliente( int cliente);

    string getPlaca() const;
    void setPlaca(const string &placa);

    double getMaxcarga() const;
    void setMaxcarga( double maxcarga);

    double getActcarga() const;
    void setActcarga( double actcarga);

};


#endif //PROYECTO_VEHICULO_H