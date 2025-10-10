//
// Created by james on 7/10/2025.
//

#ifndef INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_CURSO_H
#define INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_CURSO_H


class Curso {
private:
    char *codigo;
    char *nombre;
    double creditos;
    char **requisitos;
    int numRequisitos;

public:
    Curso();
    Curso(const Curso &);

    char *getCodigo() const;
    void setCodigo(char *codigo);
    char *getNombre() const;
    void setNombre(char *nombre);
    double getCreditos() const;
    void setCreditos(double creditos);
    char **getRequisitos() const;
    void setRequisitos(char **requisitos);
    int getNumRequisitos() const;
    void setNumRequisitos(int numRequisitos);

    Curso &operator=(const Curso &);
    void agregarRequisito(const char *nuevoRequisito);
    char *obtenerRequisito(int pos) const;
    ~Curso();
};


#endif //INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_CURSO_H
