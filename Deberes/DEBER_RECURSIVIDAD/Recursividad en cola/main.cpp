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

    function<int(int, int)> suma = [&](int i, int acum) -> int {
        if (i == n) return acum; 
        return suma(i + 1, acum + *(arr + i)); 
    };

    cout << "\nSuma total: " << suma(0, 0) << endl;

    delete[] arr;

}
