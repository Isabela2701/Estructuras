#ifndef CONTROLADORMATRIZ_H
#define CONTROLADORMATRIZ_H

#include "../Modelo/Matriz.h"
#include <iostream>
using namespace std;

template <typename T>
class ControladorMatriz {
public:
    void llenarMatriz(Matriz<T>& matriz) {
        try {
            int f = matriz.getFilas();
            int c = matriz.getColumnas();
            T valor;

            for (int i = 0; i < f; i++) {
                for (int j = 0; j < c; j++) {
                    cout << "Ingrese valor (" << i << "," << j << "): ";
                    cin >> valor;
                    matriz.setValor(i, j, valor);
                }
            }
        } catch (const char* error) {
            cout << "Error: " << error << endl;
        }
    }
};

#endif
