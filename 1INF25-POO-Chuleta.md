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
## 🔢 Sobrecarga operator[] (indexador)

### En el `.h`

```cpp
Usuario& operator[](int);
const Usuario& operator[](int) const;

Usuario& operator[](const char*);
const Usuario& operator[](const char*) const;

Usuario& at(int);
const Usuario& at(int) const;
```

### En el `.cpp`

```cpp
Usuario& RedSocial::operator[](int i) {
    if (i < 0 || i >= cantUsuarios) exit(1);
    return usuarios[i];
}

Usuario& RedSocial::operator[](const char* cuenta) {
    for (int i = 0; i < cantUsuarios; i++)
        if (strcmp(usuarios[i].getCuenta(), cuenta) == 0)
            return usuarios[i];
    cerr << "No existe la cuenta: " << cuenta << endl;
    exit(1);
}

Usuario& RedSocial::at(int i) {
    if (i < 0 || i >= cantUsuarios) exit(1);
    return (*this)[i];
}
```

### Ejemplo de uso

```cpp
Usuario u = redSocial[3];
Usuario x = redSocial.at(3);
Usuario& ref = (*this)["juan23"]; // ¡IMPORTANTE!
```

> `(*this)[cuenta]` → el paréntesis es necesario porque `this` es puntero; sin él harías aritmética de punteros (`this[cuenta]` ❌).

### Ejemplo real (profesor)

```cpp
void RedSocial::cargarPublicaciones(const char* arch) {
    Publicacion p;
    ifstream f(arch, ios::in);
    while (f >> p) {
        const char* cuenta = p.getCuenta();
        Usuario& u = (*this)[cuenta];
        u += p;
    }
}
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

## 🧰 Tipos de clases

- **Entidad:** datos (`Usuario`, `Curso`, `Publicacion`).
- **Controladora:** agrupa/gestiona (`RedSocial`).
- **Servicio/Helper:** auxiliares (`Registro`, `Archivo`).

---

## 📋 Requisitos mínimos de clase completa

- Constructor por defecto
- Constructor de copia
- Destructor
- Setters / Getters
- Sobrecarga de:
    - `=` (asignación)
    - `>>` (lectura)
    - `<<` (escritura)
    - `[]` (indexador)
    - `+=` (agregar elemento)
- Implementar `qsort` si necesita ordenamiento