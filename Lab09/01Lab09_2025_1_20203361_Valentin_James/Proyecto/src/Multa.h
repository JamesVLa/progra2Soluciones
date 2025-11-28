//
// Created by james on 27/11/2025.
//

#ifndef PROYECTO_MULTA_H
#define PROYECTO_MULTA_H
#include "Utils.h"
// JAMES VALENTIN 20203361
class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
    public:
    Multa();
    Multa(const Multa &orig);
    Multa &operator=(const Multa &orig);
    void lee(ifstream &arch);
    void imprime(ofstream& arch) const;
    int getFecha() const;
    void setFecha(const int fecha);

    string getPlaca() const;
    void setPlaca(const string &placa);

    string getCodMulta() const;
    void setCodMulta(const string &codMulta);

    double getMulta() const;
    void setMulta( double multa);

    bool isPagada() const;
    void setPagada( bool pagada);

    int getFechaDePago() const;
    void setFechaDePago( int fechaDePago);
};

ifstream& operator>>(ifstream &arch,Multa &Mult);
ofstream& operator<<(ofstream &arch,Multa &Mult);


#endif //PROYECTO_MULTA_H
