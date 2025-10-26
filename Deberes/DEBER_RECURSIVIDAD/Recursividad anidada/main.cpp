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

    function<void(int, int&)> nestedRec = [&](int i, int& res) -> void {
        if (i < 0) {
            res = 0;
            return;
        }
        
        if (i % 2 == 0) {
            int temp1, temp2;
            nestedRec(i - 1, temp1);
            nestedRec(temp1 - 1, temp2);
            res = *(arr + i) + temp2;
        } 
        else 
        {
            int temp;
            nestedRec(i - 1, temp);
            res = *(arr + i) + temp;
        }
    };

    int resultado;
    nestedRec(n - 1, resultado);
    cout << "\nResultado: " << resultado << endl;

    delete[] arr;
    return 0;
}