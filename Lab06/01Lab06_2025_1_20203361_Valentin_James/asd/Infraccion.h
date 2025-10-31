//
// Created by james on 28/10/2025.
//

#ifndef INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_INFRACCION_H
#define INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_INFRACCION_H


class Infraccion {
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
    void copiarCadena(char *&, const char *);
public:
    Infraccion();
    Infraccion(const Infraccion &);

    void setCodigo(int );
    int getCodigo() const;

    void setDescripcion(char *);
    char *getDescripcion() const;

    void setGravedad(char *);
    char *getGravedad() const;

    void setMulta(double);
    double getMulta() const;

    Infraccion &operator=(const Infraccion &);
    ~Infraccion();
};


#endif //INC_20203361_VALENTIN_JAMES_LABORATORIO06_2025_1_INFRACCION_H
