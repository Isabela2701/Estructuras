#include <iostream>
#include <cstdarg>
using namespace std;

int multiplicar(int cantidad, ...) {
    va_list lista;
    va_start(lista, cantidad);
    int producto = 1;

    for (int i = 0; i < cantidad; i++) {
        producto *= va_arg(lista, int);
    }

    va_end(lista);
    return producto;
}

int main() {
    cout << "Producto = " << multiplicar(4, 2, 3, 4, 5) << endl;
}
