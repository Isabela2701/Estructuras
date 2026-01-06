/*Se desea implementar un programa que resuelva el problema de la mochila 0/1, el cual consiste en seleccionar un subconjunto de objetos de tal forma que el valor total sea máximo, sin exceder la capacidad máxima de la mochila.

Cada objeto está caracterizado por:

Un peso

Un valor

Los objetos serán ingresados dinámicamente por teclado, sin conocerse previamente la cantidad total.
El programa debe aplicar programación dinámica para calcular el valor máximo que puede transportarse.*/


#include <iostream>
using namespace std;

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacidad, int* pesos, int* valores, int n) {

    int* dp = new int[capacidad + 1];

    for (int w = 0; w <= capacidad; w++)
        *(dp + w) = 0;

    for (int i = 0; i < n; i++) {

        if (*(pesos + i) > capacidad)
            continue;

        for (int w = capacidad; w >= *(pesos + i); w--) {
            *(dp + w) = maximo(
                *(dp + w),
                *(dp + w - *(pesos + i)) + *(valores + i)
            );
        }
    }

    int resultado = *(dp + capacidad);
    delete[] dp;
    return resultado;
}

int main() {
    int n, capacidad;

    cout << "Ingrese cantidad de objetos: ";
    cin >> n;

    int* pesos = new int[n];
    int* valores = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Peso del objeto " << i + 1 << ": ";
        cin >> *(pesos + i);
        cout << "Valor del objeto " << i + 1 << ": ";
        cin >> *(valores + i);
    }

    cout << "Ingrese capacidad de la mochila: ";
    cin >> capacidad;

    int resultado = knapsack(capacidad, pesos, valores, n);
    cout << "Valor maximo obtenido: " << resultado << endl;

    delete[] pesos;
    delete[] valores;

    return 0;
}
