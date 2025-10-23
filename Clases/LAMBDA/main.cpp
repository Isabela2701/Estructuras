#include <iostream>
#include <functional>
#include <cstdlib>
#include <limits>

int main() {
    // reservar memoria para matrices 3x3 como bloques lineales de 9 enteros
    int *m1 = static_cast<int*>(std::malloc(9 * sizeof(int)));
    int *m2 = static_cast<int*>(std::malloc(9 * sizeof(int)));
    int *res = static_cast<int*>(std::malloc(9 * sizeof(int)));

    if (!m1 || !m2 || !res) {
        std::cerr << "Fallo al asignar memoria\n";
        std::free(m1); std::free(m2); std::free(res);
        return 1;
    }

    // leer matriz desde teclado sin usar corchetes (solo aritmética de punteros)
    auto leer_matriz = [&](int *mat, const char *nombre) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int idx = i * 3 + j;
                while (true) {
                    std::cout << nombre << " (" << i + 1 << "," << j + 1 << "): ";
                    if (std::cin >> *(mat + idx)) break;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrada no valida. Intente de nuevo.\n";
                }
            }
        }
    };    // ...existing code...
} 