// ...existing code...
#include <iostream>
#include <functional>
#include <cstdlib>

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

    // inicializar m1 y m2 sin usar corchetes, solo aritmética de punteros
    *(m1 + 0) = 1; *(m1 + 1) = 2; *(m1 + 2) = 3;
    *(m1 + 3) = 4; *(m1 + 4) = 5; *(m1 + 5) = 6;
    *(m1 + 6) = 7; *(m1 + 7) = 8; *(m1 + 8) = 9;

    *(m2 + 0) = 9; *(m2 + 1) = 8; *(m2 + 2) = 7;
    *(m2 + 3) = 6; *(m2 + 4) = 5; *(m2 + 5) = 4;
    *(m2 + 6) = 3; *(m2 + 7) = 2; *(m2 + 8) = 1;

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
