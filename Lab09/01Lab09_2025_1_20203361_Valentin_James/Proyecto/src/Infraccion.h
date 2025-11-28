//
// Created by james on 27/11/2025.
//

#ifndef PROYECTO_INFRACCION_H
#define PROYECTO_INFRACCION_H
#include "Utils.h"
// JAMES VALENTIN 20203361

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
    public:

    Infraccion();
    Infraccion(const Infraccion& orig);

    Infraccion& operator=(const Infraccion& orig);
    bool operator<(const Infraccion& orig);

    ~Infraccion()=default;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    string getCodigo() const;
    void setCodigo(const string &codigo);

    double getMulta() const;
    void setMulta(double multa);

    string getGravedad() const;
    void setGravedad(const string &gravedad);

    string getDescripcion() const;
    void setDescripcion(const string &descripcion);

};

ifstream& operator>>(ifstream &arch,Infraccion &infra);
ofstream& operator<<(ofstream &arch,Infraccion &infra);
#endif //PROYECTO_INFRACCION_H