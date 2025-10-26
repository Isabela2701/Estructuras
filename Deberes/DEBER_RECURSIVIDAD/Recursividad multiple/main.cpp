#include <iostream>
#include <functional>
using namespace std;

int main() {
    int profundidad, filas, columnas;
    cout << "Ingrese profundidad: ";
    cin >> profundidad;
    cout << "Ingrese filas: ";
    cin >> filas;
    cout << "Ingrese columnas: ";
    cin >> columnas;

    int*** cube = new int**[profundidad];
    for (int k = 0; k < profundidad; k++) {
        *(cube + k) = new int*[filas];
        for (int i = 0; i < filas; i++) {
            *(*(cube + k) + i) = new int[columnas];
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << k << "][" << i << "][" << j << "]: ";
                cin >> *(*(*(cube + k) + i) + j);
            }
        }
    }

    function<void(int, int, int, int&)> suma = [&](int k, int i, int j, int& res) -> void {
        if (k == profundidad) {
            res = 0;
            return;
        }
        if (i == filas) {
            suma(k + 1, 0, 0, res);
            return;
        }
        if (j == columnas) {
            suma(k, i + 1, 0, res);
            return;
        }
        
        int temp1, temp2;
        suma(k, i, j + 1, temp1);
        suma(k + 1, i, j, temp2);
        res = *(*(*(cube + k) + i) + j) + temp1 + temp2;
    };

    int resultado;
    suma(0, 0, 0, resultado);
    cout << "\nSuma total: " << resultado << endl;

    for (int k = 0; k < profundidad; k++) {
        for (int i = 0; i < filas; i++)
            delete[] *(*(cube + k) + i);
        delete[] *(cube + k);
    }
    delete[] cube;

}
