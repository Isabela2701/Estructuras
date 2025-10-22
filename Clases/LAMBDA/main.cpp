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
    };

    leer_matriz(m1, "Matriz 1");
    leer_matriz(m2, "Matriz 2");

    // lambda recursiva para sumar elemento por elemento usando índices lineales
    std::function<void(int)> sumar = [&](int idx) {
        if (idx >= 9) return;
        *(res + idx) = *(m1 + idx) + *(m2 + idx);
        sumar(idx + 1);
    };

    sumar(0);

    // imprimir matrices usando aritmética de punteros (sin corchetes)
    auto imprimir = [&](int *mat) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int idx = i * 3 + j;
                std::cout << *(mat + idx);
                if (j < 2) std::cout << '\t';
            }
            std::cout << '\n';
        }
    };

    std::cout << "Matriz 1:\n"; imprimir(m1);
    std::cout << "Matriz 2:\n"; imprimir(m2);
    std::cout << "Suma:\n";    imprimir(res);

    std::free(m1);
    std::free(m2);
    std::free(res);
    return 0;
}
