//
// Created by james on 28/10/2025.
//

#ifndef INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_MULTA_H
#define INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_MULTA_H


class Multa {
    char* placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
    void copiarCadena(char *&, const char *);
public:
    Multa();
    Multa(const Multa& multa);
    ~Multa();
    Multa& operator=(const Multa& multa);

    void setPlaca(char *placa);
    char *getPlaca() const;
    void setFechaDeInfraccion(int fechaDeInfraccion);
    int getFechaDeInfraccion() const;
    void setFechaDePago(int fechaDePago);
    int getFechaDePago() const;
    void setCodigoInfraccion(int codigoInfraccion);
    int getCodigoInfraccion() const;
    void setMulta(double multa);
    double getMulta() const;

};


#endif //INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_MULTA_H