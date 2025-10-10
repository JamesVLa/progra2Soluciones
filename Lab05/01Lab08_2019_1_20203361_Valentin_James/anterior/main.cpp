#include <iostream>
#include "Curso.h"
#include "Alumno.h"
using namespace std;

void prueba() {
    Curso c1;
    char codigo[] = "INF101";
    char nombre[] = "Programacion I";
    c1.setCodigo(codigo);
    c1.setNombre(nombre);
    c1.setCreditos(4.0);

    c1.agregarRequisito("MAT100");
    c1.agregarRequisito("CS50");

    cout << "Curso: " << c1.getNombre() << " (" << c1.getCodigo() << ")\n";
    cout << "Requisitos: ";
    for (int i = 0; i < c1.getNumRequisitos(); ++i) {
        char *req = c1.obtenerRequisito(i);
        cout << req << " ";
        delete[] req;
    }
    cout << "\n";

    Alumno a1;
    a1.setCodigo(20203361);
    char nom[] = "James Valentin";
    a1.setNombre(nom);
    a1.agregarCurso("INF101");
    a1.agregarCurso("MAT100");

    cout << "\nAlumno: " << a1.getNombre() << " (" << a1.getCodigo() << ")\n";
    cout << "Cursos matriculados: ";
    for (int i = 0; i < a1.getNumCursos(); ++i) {
        char **cursos = a1.getCursos();
        cout << cursos[i] << " ";
        // liberar copia
        for (int j = 0; cursos[j]; ++j) delete[] cursos[j];
        delete[] cursos;
    }
    cout << "\nEsta matriculado en INF101? "
            << (a1.estaMatriculado("INF101") ? "Si" : "No") << endl;
}

int main() {
    prueba();

    return 0;
}
