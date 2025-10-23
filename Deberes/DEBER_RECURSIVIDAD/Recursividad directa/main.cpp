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

    function<int(int)> suma = [&](int i) -> int {
        if (i < 0) return 0; 
        return *(arr + i) + suma(i - 1); 
    };

    cout << "\nSuma total: " << suma(n - 1) << endl;

    delete[] arr;
}

