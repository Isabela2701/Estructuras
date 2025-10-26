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

    function<void(int, int&)> suma = [&](int i, int& acum) -> void {
        if (i == n) return; 
        acum+=* (arr+i);
        suma(i+1, acum);
    };

    int resultado=0;
    suma(0, resultado);
    cout << "\nSuma total: " <<resultado<< endl;

    delete[] arr;

}
