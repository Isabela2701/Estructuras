#include <iostream>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> *(arr + i);
    }

    function<int(int)> B; 
    function<int(int)> A = [&](int i) -> int {
        if (i == n) return 1;
        return *(arr + i) * B(i + 1);
    };
    B = [&](int i) -> int {
        if (i == n) return 1;
        return *(arr + i) * A(i + 1);
    };

    cout << "\nProducto total: " << A(0) << endl;

    delete[] arr;

}
