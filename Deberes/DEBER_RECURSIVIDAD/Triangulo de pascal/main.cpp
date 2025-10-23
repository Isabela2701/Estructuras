#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el número de filas del Triángulo de Pascal: ";
    cin >> n;
    int** pascal = new int*[n];

    for (int i = 0; i < n; i++) {
        *(pascal + i) = new int[i + 1]; 
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                *(*(pascal + i) + j) = 1; 
            } else {
                *(*(pascal + i) + j) = *(*(pascal + i - 1) + j - 1) + *(*(pascal + i - 1) + j);
            }
        }
    }
    cout << "\nTriángulo de Pascal:" << endl;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i - 1; k++) cout << "  ";
        for (int j = 0; j <= i; j++) {
            cout << *(*(pascal + i) + j) << "   ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) delete[] *(pascal + i);
    delete[] pascal;


}
