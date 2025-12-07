#ifndef GESTORARCHIVO_HPP
#define GESTORARCHIVO_HPP

#include "Alumno.hpp"
#include "Indice.hpp"
#include <fstream>

class GestorArchivo {
private:
    char* archivo;
    Indice* indice;
    int cantidad;

    char* leerLinea();
    void ordenarIndice();
    int busquedaBinaria(int legajo);

public:
    GestorArchivo(const char* nombre);
    ~GestorArchivo();

    void agregarAlumno();
    void cargarIndice();
    void mostrarIndice();
    void buscar();
};

#endif
