#include <iostream>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio del vector: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> *(arr + i);
    }

    int resultado;
    function<void(int, int&)> suma = [&](int i, int& res) -> void {
        if (i < 0) {
            res = 0;
            return;
        }
        suma(i - 1, res);
        res += *(arr + i);
    };

    suma(n - 1, resultado);
    cout << "\nSuma total: " << resultado << endl;

    delete[] arr;
    
}
