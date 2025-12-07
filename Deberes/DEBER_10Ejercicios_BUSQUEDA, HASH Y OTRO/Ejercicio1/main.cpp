#include <iostream>
#include "GestorArchivo.hpp"

int main() {
    GestorArchivo g("ALUMNOS.DAT");

    int op;
    do {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1) Agregar alumno\n";
        std::cout << "2) Cargar indice\n";
        std::cout << "3) Mostrar indice\n";
        std::cout << "4) Buscar por legajo\n";
        std::cout << "5) Salir\n";
        std::cout << "Opcion: ";
        std::cin >> op;

        switch(op) {
            case 1: g.agregarAlumno(); break;
            case 2: g.cargarIndice(); break;
            case 3: g.mostrarIndice(); break;
            case 4: g.buscar(); break;
        }

    } while(op != 5);

    return 0;
}
