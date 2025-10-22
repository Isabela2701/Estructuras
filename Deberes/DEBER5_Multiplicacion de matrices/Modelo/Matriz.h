#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <typename T>
class Matriz {
private:
    T* datos;
    int filas;
    int columnas;

public:
    Matriz() {
        datos = NULL;
        filas = 0;
        columnas = 0;
    }

    void setFilas(int f) { filas = f; }
    void setColumnas(int c) { columnas = c; }
    int getFilas() { return filas; }
    int getColumnas() { return columnas; }


    void segmentar() {
        try {
            datos = (T*)malloc(filas * columnas * sizeof(T));
            if (datos == NULL)
                throw "No se pudo reservar memoria";
        } catch (const char* error) {
            cout << "Error: " << error << endl;
        }
    }

    void encerar() {
        int total = filas * columnas;
        for (int i = 0; i < total; i++) {
            *(datos + i) = 0;
        }
    }

    void setValor(int fila, int col, T valor) {
        if (fila < 0 || fila >= filas || col < 0 || col >= columnas)
            throw "Indice fuera de rango";
        *(datos + fila * columnas + col) = valor;
    }

   
    T getValor(int fila, int col) {
        if (fila < 0 || fila >= filas || col < 0 || col >= columnas)
            throw "Indice fuera de rango";
        return *(datos + fila * columnas + col);
    }

 
    Matriz operator*(Matriz& otra) {
        if (columnas != otra.getFilas())
            throw "Dimensiones incompatibles para multiplicacion";

        Matriz resultado;
        resultado.setFilas(filas);
        resultado.setColumnas(otra.getColumnas());
        resultado.segmentar();
        resultado.encerar();

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < otra.getColumnas(); j++) {
                T suma = 0;
                for (int k = 0; k < columnas; k++) {
                    T a = *(datos + i * columnas + k);
                    T b = *(otra.datos + k * otra.getColumnas() + j);
                    suma += a * b;
                }
                *(resultado.datos + i * resultado.getColumnas() + j) = suma;
            }
        }
        return resultado;
    }


    void mostrar() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << setw(8) << *(datos + i * columnas + j);
            }
            cout << endl;
        }
    }

    void liberar() {
        if (datos != NULL) {
            free(datos);
            datos = NULL;
        }
    }
};

#endif
