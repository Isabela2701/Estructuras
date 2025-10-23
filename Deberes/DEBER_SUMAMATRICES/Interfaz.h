#ifndef INTERFAZ_H
#define INTERFAZ_H

class Interfaz {
public:
    virtual void encerar(int ***&matriz, int &profundidad, int &filas, int &columnas) = 0;
    virtual int ***segmenta(int &profundidad, int &filas, int &columnas) = 0;
    virtual void ingresarDatos(int ***matriz, int profundidad, int filas, int columnas) = 0;
    virtual void imprimirMatriz(int ***matriz, int profundidad, int filas, int columnas) = 0;
};

#endif
