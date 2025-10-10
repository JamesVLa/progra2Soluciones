//
// Created by james on 8/10/2025.
//

#ifndef PROBANDO_PRUEBA_H
#define PROBANDO_PRUEBA_H


class prueba {
    char* textoBien;
    char* textoMal;
public:
    prueba();
    ~prueba();

    void setTextoBien(const char* txt);
    void setTextoMal(const char* txt);

    char* getTextoBien() const;
    char* getTextoMal() const;

};


#endif //PROBANDO_PRUEBA_H