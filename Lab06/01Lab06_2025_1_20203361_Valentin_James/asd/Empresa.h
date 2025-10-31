//
// Created by james on 28/10/2025.
//

#ifndef INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_EMPRESA_H
#define INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_EMPRESA_H
#include "Multa.h"


class Empresa {
private:
    int dni;
    char* nombre;
    char* placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;
    void copiarCadena(char *&, const char *);
    public:

    Empresa();
    Empresa(const Empresa &);

    Empresa &operator=(const Empresa &);
    ~Empresa();

    void setDni(int );
    int getDni() const;

    void setNombre(char * const nombre);
    char * getNombre() const;

    void setPlacaI( char * placa,int i);
    char * getPlacaI(int i) const;

    void setNumPlacas( int numPlacas);
    int getNumPlacas() const;

    void setNumMultas( int numMultas);
    int getNumMultas() const;

    void agregarPlaca(char *placa);
    void agregarMulta(Multa &m);
};


#endif //INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_EMPRESA_H