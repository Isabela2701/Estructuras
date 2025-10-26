#include <iostream>
#include <functional>
using namespace std;

int main() {
    int filas, columnas;
    cout << "Ingrese número de filas: ";
    cin >> filas;
    cout << "Ingrese número de columnas: ";
    cin >> columnas;

    int** mat = new int*[filas];
    for (int i = 0; i < filas; i++) {
        *(mat + i) = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> *(*(mat + i) + j);
        }
    }

    function<void(int, int, int&)> mult = [&](int i, int j, int& res) -> void {
        if (i == filas) {
            res = 1;
            return;
        }
        if (j == columnas) {
            mult(i + 1, 0, res);
            return;
        }
        int temp;
        mult(i, j + 1, temp);
        res = *(*(mat + i) + j) * temp;
    };

    int resultado;
    mult(0, 0, resultado);
    cout << "\nProducto total: " << resultado << endl;

    for (int i = 0; i < filas; i++) delete[] *(mat + i);
    delete[] mat;
}