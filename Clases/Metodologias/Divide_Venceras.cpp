
/*Se desea desarrollar un programa que permita realizar la búsqueda de un valor entero dentro de un conjunto de números enteros ordenados en forma ascendente.

Los valores serán ingresados dinámicamente por teclado, sin conocerse previamente la cantidad de elementos.
Una vez ingresados los datos, el programa deberá aplicar el algoritmo de búsqueda binaria recursiva, siguiendo la metodología Divide y Vencerás, para determinar si un valor objetivo se encuentra en el conjunto.*/ 
#include <iostream>
using namespace std;

int binarySearch(int* base, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    int* midPtr = base + mid;

    if (*midPtr == target)
        return mid;

    if (*midPtr > target)
        return binarySearch(base, left, mid - 1, target);

    return binarySearch(base, mid + 1, right, target);
}

int main() {
    int* datos = nullptr;
    int n = 0;
    char continuar;

    do {
        int* nuevo = new int[n + 1];

        for (int i = 0; i < n; i++)
            *(nuevo + i) = *(datos + i);

        delete[] datos;
        datos = nuevo;
        cout << "Ingrese un numero (orden ascendente): ";
        cin >> *(datos + n);
        n++;

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    int target;
    cout << "\nIngrese el valor a buscar: ";
    cin >> target;

    int resultado = binarySearch(datos, 0, n - 1, target);

    cout << "Indice: " << resultado << endl;

    delete[] datos;
    return 0;
}
