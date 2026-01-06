/*Se dispone de un conjunto de actividades, cada una caracterizada por un tiempo de inicio y un tiempo de finalización.
El objetivo es seleccionar el máximo número de actividades compatibles, entendiendo como compatibles aquellas actividades cuyo tiempo de inicio sea mayor o igual al tiempo de finalización de la actividad previamente seleccionada.*/

#include <iostream>
using namespace std;

// Ordenamiento burbuja por tiempo de finalización
void ordenarPorFin(int* inicio, int* fin, int n) {
    int* i;
    int* j;
    int temp;

    for (i = fin; i < fin + n - 1; i++) {
        for (j = fin; j < fin + n - 1 - (i - fin); j++) {
            if (*j > *(j + 1)) {
                // Intercambiar fin
                temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;

                // Intercambiar inicio asociado
                temp = *(inicio + (j - fin));
                *(inicio + (j - fin)) = *(inicio + (j - fin) + 1);
                *(inicio + (j - fin) + 1) = temp;
            }
        }
    }
}

int main() {
    int* inicio = nullptr;
    int* fin = nullptr;
    int n = 0;
    char continuar;

    do {
        // Redimensionar memoria
        int* nuevoInicio = new int[n + 1];
        int* nuevoFin = new int[n + 1];

        for (int i = 0; i < n; i++) {
            *(nuevoInicio + i) = *(inicio + i);
            *(nuevoFin + i) = *(fin + i);
        }

        delete[] inicio;
        delete[] fin;

        inicio = nuevoInicio;
        fin = nuevoFin;

        // Ingreso de datos
        cout << "Ingrese inicio de la actividad: ";
        cin >> *(inicio + n);

        cout << "Ingrese fin de la actividad: ";
        cin >> *(fin + n);

        n++;

        cout << "Desea ingresar otra actividad? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // Ordenar manualmente por tiempo de finalización
    ordenarPorFin(inicio, fin, n);

    // Algoritmo voraz
    int count = 1;
    int lastEnd = *fin;

    int* pInicio = inicio + 1;
    int* pFin = fin + 1;

    while (pFin < fin + n) {
        if (*pInicio >= lastEnd) {
            count++;
            lastEnd = *pFin;
        }
        pInicio++;
        pFin++;
    }

    cout << "\nMaximo numero de actividades compatibles: "
         << count << endl;

    delete[] inicio;
    delete[] fin;

    return 0;
}
