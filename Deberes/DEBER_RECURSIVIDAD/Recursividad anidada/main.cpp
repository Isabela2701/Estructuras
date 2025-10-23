#include <iostream>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio de vector: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> *(arr + i);
    }

    function<int(int)> nestedRec = [&](int i) -> int {
        if (i < 0) return 0;
        if (i % 2 == 0)
            return *(arr + i) + nestedRec(nestedRec(i - 1) - 1);
        else
            return *(arr + i) + nestedRec(i - 1);
    };

    cout << "\nResultado: " << nestedRec(n - 1) << endl;

    delete[] arr;
    return 0;
}
