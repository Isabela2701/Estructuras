// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "MatlabEngine.hpp"
#include "MatlabDataArray.hpp"

using namespace std;
using namespace matlab::engine;

// Función para graficar usando MATLAB Engine
void graficarBigO(std::shared_ptr<MATLABEngine> matlabPtr) {
    try {
        // Vector de tamaños de problema (n)
        matlab::data::ArrayFactory factory;
        std::vector<double> n_values = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        auto n_array = factory.createArray({ 1, n_values.size() }, n_values.begin(), n_values.end());

        // Valores teóricos de O(n!) (para comparación)
        std::vector<double> factorial_values;
        for (int i = 1; i <= 9; i++) {
            double fact = 1;
            for (int j = 1; j <= i; j++) fact *= j;
            factorial_values.push_back(fact);
        }
        auto fact_array = factory.createArray({ 1, factorial_values.size() }, factorial_values.begin(), factorial_values.end());

        // Configuración del gráfico
        matlabPtr->setVariable(u"n", n_array, matlab::engine::WorkspaceType::BASE);
        matlabPtr->setVariable(u"O_factorial", fact_array, matlab::engine::WorkspaceType::BASE);

        // Comandos MATLAB para crear el gráfico
        matlabPtr->eval(u"figure('Position', [100, 100, 800, 600]);");
        matlabPtr->eval(u"hold on;");
        matlabPtr->eval(u"grid on;");

        // Graficar n! (complejidad teórica)
        matlabPtr->eval(u"plot(n, O_factorial, 'b-', 'LineWidth', 2, 'DisplayName', 'O(n!)');");

        // Graficar 9! (complejidad máxima para n=9)
        matlabPtr->eval(u"plot(9, factorial(9), 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'r', 'DisplayName', '9! = 362880');");

        // Configuración del gráfico
        matlabPtr->eval(u"xlabel('n (tamaño del problema)');");
        matlabPtr->eval(u"ylabel('Operaciones (escala logarítmica)');");
        matlabPtr->eval(u"title('Complejidad Big O: O(n!) para Backtracking');");
        matlabPtr->eval(u"legend('show', 'Location', 'northwest');");
        matlabPtr->eval(u"set(gca, 'YScale', 'log');");
        matlabPtr->eval(u"xlim([0, 10]);");

        // Anotaciones
        matlabPtr->eval(u"text(9, factorial(9), sprintf(' 9! = %.0f', factorial(9)), 'VerticalAlignment', 'bottom');");

        cout << "\nGráfico generado en MATLAB." << endl;

    }
    catch (const std::exception& e) {
        cerr << "Error al generar gráfico: " << e.what() << endl;
    }
}

void imprimir(int A, int B, int C, int D, int E, int F, int G, int H, int I) {

    cout << "        " << A << "               " << D << endl;
    cout << "            " << B << "       " << E << endl;
    cout << "                [" << C << "]" << endl;
    cout << "                 " << F << endl;
    cout << "        " << H << "       " << G << "       " << I << endl;
    cout << "----------------------------------------" << endl;
}

void backtrack(
    int pos,
    int usados,
    int A, int B, int C, int D, int E, int F, int G, int H, int I,
    int& soluciones
) {
    if (pos == 9) {
        soluciones++;
        cout << "Solucion " << soluciones << endl;
        imprimir(A, B, C, D, E, F, G, H, I);
        return;
    }

    for (int num = 1; num <= 9; num++) {

        if (usados & (1 << num)) continue;

        if (pos == 0) backtrack(1, usados | (1 << num), num, B, C, D, E, F, G, H, I, soluciones);
        else if (pos == 1) backtrack(2, usados | (1 << num), A, num, C, D, E, F, G, H, I, soluciones);
        else if (pos == 2) {
            if (A + B + num != 14) continue;
            backtrack(3, usados | (1 << num), A, B, num, D, E, F, G, H, I, soluciones);
        }
        else if (pos == 3) backtrack(4, usados | (1 << num), A, B, C, num, E, F, G, H, I, soluciones);
        else if (pos == 4) {
            if (D + num + C != 14) continue;
            backtrack(5, usados | (1 << num), A, B, C, D, num, F, G, H, I, soluciones);
        }
        else if (pos == 5) backtrack(6, usados | (1 << num), A, B, C, D, E, num, G, H, I, soluciones);
        else if (pos == 6) {
            if (C + F + num != 14) continue;
            backtrack(7, usados | (1 << num), A, B, C, D, E, F, num, H, I, soluciones);
        }
        else if (pos == 7) backtrack(8, usados | (1 << num), A, B, C, D, E, F, G, num, I, soluciones);
        else if (pos == 8) {
            if (H + G + num != 14) continue;
            backtrack(9, usados | (1 << num), A, B, C, D, E, F, G, H, num, soluciones);
        }
    }
}


int main() {
    int soluciones = 0;

    // Crear instancia de MATLAB Engine
    std::shared_ptr<MATLABEngine> matlabPtr;
    try {
        cout << "Iniciando MATLAB Engine..." << endl;
        matlabPtr = startMATLAB();

        // Ejecutar backtracking
        cout << "Ejecutando algoritmo de backtracking..." << endl;
        backtrack(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, soluciones);

        cout << "Total de soluciones: " << soluciones << endl;

        // Generar gráfico del Big O
        cout << "\nGenerando gráfico de complejidad Big O..." << endl;
        graficarBigO(matlabPtr);

        cout << "\nPresiona Enter para cerrar el gráfico y finalizar..." << endl;
        cin.get();

    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
