#include <iostream>
#include <cstdarg>
using namespace std;

void mostrarTextos(int cantidad, ...) {
    va_list lista;
    va_start(lista, cantidad);

    for (int i = 0; i < cantidad; i++) {
        const char* texto = va_arg(lista, const char*);
        cout << texto << " ";
    }

    va_end(lista);
    cout << endl;
}

int main() {
    mostrarTextos(4, "Hola", "mundo", "desde", "C++!");
    return 0;
}
