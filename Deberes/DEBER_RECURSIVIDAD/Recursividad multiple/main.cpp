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

    function<int(int, int, int)> suma= [&](int k, int i, int j) -> int {
        if (k == profundidad) return 0;
        if (i == filas) return suma(k + 1, 0, 0);
        if (j == columnas) return suma(k, i + 1, 0);
        return *(*(*(cube + k) + i) + j)
               + suma(k, i, j + 1)
               + suma(k + 1, i, j); 
    };

    cout << "\nSuma total: " << suma(0, 0, 0) << endl;

    for (int k = 0; k < profundidad; k++) {
        for (int i = 0; i < filas; i++)
            delete[] *(*(cube + k) + i);
        delete[] *(cube + k);
    }
    delete[] cube;

}
