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

    function<int(int, int)> mult= [&](int i, int j) -> int {
        if (i == filas) return 1;
        if (j == columnas) return mult(i + 1, 0);
        return *(*(mat + i) + j) * mult(i, j + 1); 
    };

    cout << "\nProducto total: " << mult(0, 0) << endl;

    for (int i = 0; i < filas; i++) delete[] *(mat + i);
    delete[] mat;
    return 0;
}
