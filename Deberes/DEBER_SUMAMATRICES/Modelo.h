#ifndef MODELO_H
#define MODELO_H
#include <iostream>
using namespace std;

class Modelo {
private:
    int ***matriz;
    int profundidad;
    int filas;
    int columnas;

public:
    
    Modelo() {
        matriz = nullptr;
        profundidad = filas = columnas = 0;
    }

    
    void setProfundidad(int p) { profundidad = p; }
    void setFilas(int f) { filas = f; }
    void setColumnas(int c) { columnas = c; }
    void setMatriz(int ***m) { matriz = m; }

    int getProfundidad() { return profundidad; }
    int getFilas() { return filas; }
    int getColumnas() { return columnas; }
    int ***getMatriz() { return matriz; }
};

#endif
