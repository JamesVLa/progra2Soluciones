//
// Created by james on 8/10/2025.
//

#ifndef PREGUNTA01_CURSO_H
#define PREGUNTA01_CURSO_H


class Curso {
private:
    char *codigo;
    char *nombre;
    double creditos;
    char **requisitos;
    int numRequisitos;
public:
    Curso();
    Curso(const Curso& origen);
    ~Curso();
    char * getCodigo() const;
    void setCodigo(char *codigo);
    char * getNombre() const;
    void setNombre(char *nombre);
    double getCreditos() const;
    void setCreditos(double creditos);
    char ** getRequisitos() const;
    void setRequisitos(char **requisitos);
    int getNumRequisitos() const;
    void setNumRequisitos(int numRequisitos);

};


#endif //PREGUNTA01_CURSO_H