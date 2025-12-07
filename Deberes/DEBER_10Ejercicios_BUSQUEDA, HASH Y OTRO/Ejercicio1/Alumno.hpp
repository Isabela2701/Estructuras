#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <iostream>
#include <cstring>

class Alumno {
private:
    int legajo;
    char* nombre;
    char* carrera;

    void copiarCadena(char*& destino, const char* origen);

public:
    Alumno();
    Alumno(int leg, const char* nom, const char* car);
    ~Alumno();

    int getLegajo() const;
    const char* getNombre() const;
    const char* getCarrera() const;

    void setLegajo(int l);
    void setNombre(const char* nom);
    void setCarrera(const char* car);

    void mostrar() const;
};

#endif
