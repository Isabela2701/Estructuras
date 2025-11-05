#include <iostream>
#include <cstdarg>   // Para va_list, va_start, va_arg, va_end
#include <cstdlib>   // Para malloc y free
using namespace std;

// -----------------------------
// FUNCIONES AUXILIARES
// -----------------------------

// Reserva memoria para una matriz tridimensional
int*** crearMatriz3D(int filas, int columnas, int profundidad) {
    int*** matriz = (int***)malloc(filas * sizeof(int**));
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = (int**)malloc(columnas * sizeof(int*));
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = (int*)malloc(profundidad * sizeof(int));
        }
    }
    return matriz;
}

// Libera la memoria de una matriz 3D
void liberarMatriz3D(int*** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            free(*(*(matriz + i) + j));
        }
        free(*(matriz + i));
    }
    free(matriz);
}

// Inicializa una matriz 3D con valores consecutivos (solo ejemplo)
void llenarMatriz3D(int*** matriz, int filas, int columnas, int profundidad, int inicio) {
    int valor = inicio;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            for (int k = 0; k < profundidad; k++) {
                *(*(*(matriz + i) + j) + k) = valor++;
            }
        }
    }
}

// Muestra los valores de una matriz 3D
void mostrarMatriz3D(int*** matriz, int filas, int columnas, int profundidad) {
    for (int i = 0; i < filas; i++) {
        cout << "Capa " << i + 1 << ":" << endl;
        for (int j = 0; j < columnas; j++) {
            for (int k = 0; k < profundidad; k++) {
                cout << *(*(*(matriz + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// -----------------------------
// FUNCIÓN VARIÁDICA (...)
// -----------------------------
void sumarMatrices3D(int cantidad, int filas, int columnas, int profundidad, int**** resultado, ...) {
    va_list args;
    va_start(args, resultado);

    // Inicializar resultado en 0
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            for (int k = 0; k < profundidad; k++)
                *(*(*(*resultado + i) + j) + k) = 0;

    // Recorrer todas las matrices recibidas
    for (int m = 0; m < cantidad; m++) {
        int*** matriz = va_arg(args, int***);

        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                for (int k = 0; k < profundidad; k++)
                    *(*(*(*resultado + i) + j) + k) += *(*(*(matriz + i) + j) + k);
    }

    va_end(args);
}

// -----------------------------
// PROGRAMA PRINCIPAL
// -----------------------------
int main() {
    int filas = 2, columnas = 2, profundidad = 2;

    // Crear matrices dinámicas
    int*** A = crearMatriz3D(filas, columnas, profundidad);
    int*** B = crearMatriz3D(filas, columnas, profundidad);
    int*** C = crearMatriz3D(filas, columnas, profundidad);
    int*** R = crearMatriz3D(filas, columnas, profundidad); // resultado

    // Llenar con valores
    llenarMatriz3D(A, filas, columnas, profundidad, 1);
    llenarMatriz3D(B, filas, columnas, profundidad, 10);
    llenarMatriz3D(C, filas, columnas, profundidad, 100);

    cout << "Matriz A:\n"; mostrarMatriz3D(A, filas, columnas, profundidad);
    cout << "Matriz B:\n"; mostrarMatriz3D(B, filas, columnas, profundidad);
    cout << "Matriz C:\n"; mostrarMatriz3D(C, filas, columnas, profundidad);

    // Sumar usando parámetro variádico
    sumarMatrices3D(3, filas, columnas, profundidad, &R, A, B, C);

    cout << "Resultado (A + B + C):\n";
    mostrarMatriz3D(R, filas, columnas, profundidad);

    // Liberar memoria
    liberarMatriz3D(A, filas, columnas);
    liberarMatriz3D(B, filas, columnas);
    liberarMatriz3D(C, filas, columnas);
    liberarMatriz3D(R, filas, columnas);

    return 0;
}
