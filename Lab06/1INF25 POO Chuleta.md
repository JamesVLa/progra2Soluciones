# ⚡ Chuleta rápida – Clases, Constructores, Sobrecarga y qsort (C++)

---

## 📄 Usuario.h

```cpp
#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
public:
    // Constructores / Destructor
    Usuario();                            // por defecto
    Usuario(char* cuenta, char* nombre);  // propiamente dicho
    Usuario(const Usuario&);              // copia
    ~Usuario();                           // destructor

    // Setters / Getters
    void setCuenta(char* c);
    char* getCuenta() const;

    // Sobrecarga de asignación
    Usuario& operator=(const Usuario&);

    // Getter adicional para ejemplo qsort
    int getEdad() const { return edad; }

private:
    char* cuenta;
    char* nombre;
    int edad;
};

// Función de comparación para qsort
int compararUsuarios(const void* a, const void* b);

#endif
```

---

## ⚙️ Usuario.cpp

```cpp
#include "Usuario.h"
#include <cstring>
#include <cstdlib> // qsort

// ---------- Constructores / Destructor ----------

// Constructor por defecto
Usuario::Usuario() : cuenta(nullptr), nombre(nullptr), edad(0) {}

// Constructor propiamente dicho
Usuario::Usuario(char* cuenta_, char* nombre_)
    : Usuario() { // llama al constructor por defecto
    setCuenta(cuenta_);
    // setNombre(nombre_);
}

// Constructor de copia
Usuario::Usuario(const Usuario& origen) : Usuario() {
    *this = origen; // reutiliza operator=
}

// Destructor
Usuario::~Usuario() {
    delete[] cuenta;
    delete[] nombre;
}

// ---------- Operador = ----------
Usuario& Usuario::operator=(const Usuario& origen) {
    if (this == &origen) return *this;
    setCuenta(origen.getCuenta());
    // setNombre(origen.getNombre());
    edad = origen.edad;
    return *this;
}

// ---------- Getters ----------
char* Usuario::getCuenta() const { return cuenta; }

// ---------- Setters: 3 opciones para char* ----------

// 🟢 Opción 1: Versión básica
void Usuario::setCuenta(char* c) {
    delete[] this->cuenta;
    if (c) {
        this->cuenta = new char[strlen(c) + 1];
        strcpy(this->cuenta, c);
    } else this->cuenta = nullptr;
}

// 🟢 Opción 2: Genérica (usa función auxiliar)
void setCadenaGeneric(char*& destino, const char* origen) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    } else destino = nullptr;
}

void Usuario::setCuenta(char* c) {
    setCadenaGeneric(this->cuenta, c);
}

// 🟢 Opción 3: Con mi_strdup
char* mi_strdup(const char* s) {
    if (!s) return nullptr;
    char* copia = new char[strlen(s) + 1];
    strcpy(copia, s);
    return copia;
}

void Usuario::setCuenta(char* c) {
    delete[] this->cuenta;
    this->cuenta = mi_strdup(c);
}
```

---

## 🧩 Utilidades comunes

Estas funciones son útiles para liberar o duplicar cadenas sin repetir código.

```cpp
// Copia cadena (versión genérica)
void setCadenaGeneric(char*& destino, const char* origen);

// Duplica una cadena nueva
char* mi_strdup(const char* s);

// Libera memoria de cadena y pone puntero en nullptr
void libera_cadena(char *&cadena) {
    if (cadena != nullptr) {
        delete[] cadena; // usar delete[] si fue asignado con new[]
        cadena = nullptr;
    }
}
```

💡 _Recuerda usar `delete[]` en lugar de `delete` simple cuando hayas hecho `new[]`._

---

## 🔢 qsort

```cpp
int compararUsuarios(const void* a, const void* b) {
    const Usuario* ua = (const Usuario*)a;
    const Usuario* ub = (const Usuario*)b;
    return ua->getEdad() - ub->getEdad();
}

// Uso:
qsort(usuarios, cantUsuarios, sizeof(Usuario), compararUsuarios);
```

---

## 💡 Recordatorios rápidos

|Concepto|Sintaxis / Uso|
|---|---|
|Constructor copia|`Clase(const Clase&);`|
|Destructor|`~Clase();`|
|Asignación|`Clase& operator=(const Clase&);`|
|Crear objeto|`Clase obj;`|
|Crear puntero|`Clase* p = new Clase; delete p;`|
|delete seguro|`delete[] nullptr;` ✅|
|Evitar duplicar código|Usa `setCadenaGeneric()` o `mi_strdup()`|
|Liberar cadena|`libera_cadena(ptr);`|
|Ordenar con qsort|`qsort(arr, n, sizeof(T), comparar);`|