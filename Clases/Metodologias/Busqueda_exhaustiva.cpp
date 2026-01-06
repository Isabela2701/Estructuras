/*Se dispone de un conjunto finito de números enteros positivos almacenados en memoria de forma contigua.
Dado un valor objetivo, se desea determinar si existe al menos un subconjunto de dichos números cuya suma sea exactamente igual al valor objetivo.

El problema debe resolverse aplicando búsqueda exhaustiva, evaluando todas las combinaciones posibles de inclusión y exclusión de elementos del conjunto.*/

#include <iostream>
#include <cstdlib>
using namespace std;

bool subsetSum(int* ptr, int n, int target) {
    // Caso base: se alcanzó la suma objetivo
    if (target == 0)
        return true;

    // Caso base: no quedan elementos o la suma es negativa
    if (n == 0 || target < 0)
        return false;

    // Opción 1: incluir el elemento apuntado
    // Opción 2: excluirlo y avanzar el puntero
    return subsetSum(ptr + 1, n - 1, target - *ptr) ||
           subsetSum(ptr + 1, n - 1, target);
}

int main() {
    int n;
    cout << "Ingrese el número de elementos: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Entrada inválida\n";
        return 1;
    }

    int* datos = (int*)malloc(n * sizeof(int));
    if (!datos) {
        cout << "Error de asignación\n";
        return 1;
    }
    cout << "Ingrese los elementos separados por espacios: ";
    for (int i = 0; i < n; ++i)
        cin >> *(datos + i);

    int objetivo;
    cout << "Ingrese el objetivo: ";
    cin >> objetivo;

    int* p = datos;

    if (subsetSum(p, n, objetivo))
        cout << "Existe subconjunto";
    else
        cout << "No existe subconjunto";

    cout << "\n";
    free(datos);
    return 0;
}
