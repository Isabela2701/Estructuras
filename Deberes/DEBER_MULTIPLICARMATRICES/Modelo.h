#ifndef MODELO_H
#define MODELO_H
#include <iostream>
#include <cstdlib>
using namespace std;

// ---------- TDA GENERICO ----------
template<typename T>
class Matriz3D {
private:
    int x, y, z;     // Dimensiones
    T*** datos;      // Puntero triple
public:
    // Constructor
    Matriz3D(int _x, int _y, int _z) {
        x = _x; y = _y; z = _z;
        segmentar();
        encerar();
    }

    // ---------- SEGMENTAR ----------
    void segmentar() {
        datos = (T***)malloc(x * sizeof(T**));
        for (int i = 0; i < x; i++) {
            *(datos + i) = (T**)malloc(y * sizeof(T*));
            for (int j = 0; j < y; j++) {
                *(*(datos + i) + j) = (T*)malloc(z * sizeof(T));
            }
        }
    }

    // ---------- ENCERRAR (INICIALIZAR EN CERO) ----------
    void encerar() {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    *(*(* (datos + i) + j) + k) = 0;
                }
            }
        }
    }

    // ---------- INGRESAR DATOS ----------
    void ingresar() {
        auto leerValor = [](const char* msg) -> T {
            T valor;
            cout << msg;
            cin >> valor;
            return valor;
        };

        cout << "\n--- Ingreso de datos de la matriz ---\n";
        for (int i = 0; i < x; i++) {
            cout << "Capa " << i + 1 << ":\n";
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    *(*(* (datos + i) + j) + k) = leerValor("Valor: ");
                }
            }
        }
    }

    // ---------- MOSTRAR MATRIZ ----------
    void mostrar() {
        for (int i = 0; i < x; i++) {
            cout << "\nCapa " << i + 1 << ":\n";
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    cout << *(*(* (datos + i) + j) + k) << " ";
                }
                cout << endl;
            }
        }
    }

    // ---------- SOBRECARGA DE * PARA MULTIPLICACIÓN ----------
    Matriz3D operator*(Matriz3D& B) {
        if (y != B.x || z != B.z) {
            cout << "No se pueden multiplicar las matrices 3D (dimensiones incompatibles)\n";
            exit(1);
        }

        Matriz3D<T> resultado(x, B.y, z);

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < B.y; j++) {
                for (int k = 0; k < z; k++) {
                    T suma = 0;
                    for (int m = 0; m < y; m++) {
                        suma += *(*(*(datos + i) + m) + k) * *(*(*(B.datos + m) + j) + k);
                    }
                    *(*(*(resultado.datos + i) + j) + k) = suma;
                }
            }
        }
        return resultado;
    }

    // ---------- DESTRUCTOR ----------
    ~Matriz3D() {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                free(*(*(datos + i) + j));
            }
            free(*(datos + i));
        }
        free(datos);
    }
};

#endif
