#include <iostream>
#include "Interfaz.h"
#include "Modelo.h"
#include <functional>
using namespace std;

class VistaControlador : public Interfaz {
public:
    void encerar(int ***&matriz, int &profundidad, int &filas, int &columnas) {
        matriz = new int**[profundidad];
        for (int k = 0; k < profundidad; k++) {
            *(matriz + k) = new int*[filas];
            for (int i = 0; i < filas; i++) {
                *(*(matriz + k) + i) = new int[columnas];
                for (int j = 0; j < columnas; j++)
                    *(*(*(matriz + k) + i) + j) = 0;
            }
        }
    }

    int ***segmenta(int &profundidad, int &filas, int &columnas) {
        int ***matriz;
        matriz = new int**[profundidad];
        for (int k = 0; k < profundidad; k++) {
            *(matriz + k) = new int*[filas];
            for (int i = 0; i < filas; i++)
                *(*(matriz + k) + i) = new int[columnas];
        }
        return matriz;
    }

    void ingresarDatos(int ***matriz, int profundidad, int filas, int columnas) {
        for (int k = 0; k < profundidad; k++) {
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << "Elemento [" << k << "][" << i << "][" << j << "]: ";
                    cin >> *(*(*(matriz + k) + i) + j);
                }
            }
        }
    }

    void imprimirMatriz(int ***matriz, int profundidad, int filas, int columnas) {
        for (int k = 0; k < profundidad; k++) {
            cout << "Profundidad " << k << ":" << endl;
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++)
                    cout << *(*(*(matriz + k) + i) + j) << " ";
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    VistaControlador vc;
    Modelo m1, m2, suma;

    int profundidad, filas, columnas;
    cout << "Ingrese profundidad: "; cin >> profundidad;
    cout << "Ingrese filas: "; cin >> filas;
    cout << "Ingrese columnas: "; cin >> columnas;

    m1.setProfundidad(profundidad);
    m1.setFilas(filas);
    m1.setColumnas(columnas);
    m2.setProfundidad(profundidad);
    m2.setFilas(filas);
    m2.setColumnas(columnas);

    int ***matriz1 = vc.segmenta(profundidad, filas, columnas);
    int ***matriz2 = vc.segmenta(profundidad, filas, columnas);
    int ***matrizSuma = vc.segmenta(profundidad, filas, columnas);

    m1.setMatriz(matriz1);
    m2.setMatriz(matriz2);
    suma.setMatriz(matrizSuma);

    cout << "\nIngrese datos de la primera matriz:\n";
    vc.ingresarDatos(m1.getMatriz(), profundidad, filas, columnas);

    cout << "\nIngrese datos de la segunda matriz:\n";
    vc.ingresarDatos(m2.getMatriz(), profundidad, filas, columnas);

    
    function<void(int, int, int)> sumarLambda = [&](int k, int i, int j) {
        if (k == profundidad) return;
        if (i == filas) { sumarLambda(k + 1, 0, 0); return; }
        if (j == columnas) { sumarLambda(k, i + 1, 0); return; }

        *(*(*(matrizSuma + k) + i) + j) = *(*(*(matriz1 + k) + i) + j) + *(*(*(matriz2 + k) + i) + j);
        sumarLambda(k, i, j + 1);
    };

    sumarLambda(0, 0, 0);

    cout << "\nMatriz resultante de la suma:\n";
    vc.imprimirMatriz(matrizSuma, profundidad, filas, columnas);

    // Liberar memoria
    for (int k = 0; k < profundidad; k++) {
        for (int i = 0; i < filas; i++) {
            delete[] *(matriz1 + k);
            delete[] *(matriz2 + k);
            delete[] *(matrizSuma + k);
        }
        delete[] *(matriz1 + k);
        delete[] *(matriz2 + k);
        delete[] *(matrizSuma + k);
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] matrizSuma;
}
