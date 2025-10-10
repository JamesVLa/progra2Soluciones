//
// Created by james on 7/10/2025.
//

#ifndef INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_ALUMNO_H
#define INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_ALUMNO_H
#include <fstream>
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    char **cursos;
    int numCursos;

public:
    Alumno();
    Alumno(const Alumno &);
    Alumno &operator=(const Alumno &);

    ~Alumno();
    int getCodigo() const;
    void setCodigo(int codigo);
    char *getNombre() const;
    void setNombre(char *nombre);
    char **getCursos() const;
    void setCursos(char **cursos);
    int getNumCursos() const;
    void setNumCursos(int numCursos);
    void agregarCurso(const char *nuevoCurso);
    bool estaMatriculado(const char *codigoCurso) const;
    char* leerCadena(istream&, char delim = ',');

};

istream& operator>>(istream&, Alumno&);
ostream& operator<<(ostream&, const Alumno&);


#endif //INC_20203361_VALENTIN_JAMES_LABORATORIO08_2019_1_ALUMNO_H
