#include <iostream>
#include <functional>

int main() {
    int num;
    int* resultado = new int;
    std::cout << "Ingrese un entero >= 0: ";
    if (!(std::cin >> num) || num < 0) {
        std::cerr << "Entrada no valida\n";
        delete resultado;
        return 1;
    }

    std::function<void(int)> factorial;
    factorial = [&](int n) {
        if (n <= 1) {
            *resultado = 1;
            return;
        }
        factorial(n - 1);
        *resultado *= n;
    };

    factorial(num);
    std::cout << num << "! = " << *resultado << '\n';

    delete resultado;
    return 0;
}

