#include <iostream>
using namespace std;

/* Calcula el término a_n del patrón */
int termino(int n, int a1, int d) {
    if (n == 1)
        return a1;                  // Caso base
    return termino(n - 1, a1, d) + d; // Definición recursiva
}

/* Suma exhaustiva del patrón */
int suma(int n, int a1, int d) {
    if (n == 1)
        return a1;                  // Caso base
    return suma(n - 1, a1, d) + termino(n, a1, d);
}

int main() {
    int n, a1, d;

    cout << "Ingrese el numero de terminos: ";
    cin >> n;

    cout << "Ingrese el primer termino (a1): ";
    cin >> a1;

    cout << "Ingrese la diferencia (d): ";
    cin >> d;

    cout << "La suma del patron es: " << suma(n, a1, d) << endl;

    return 0;
}
