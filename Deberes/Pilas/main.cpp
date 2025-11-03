#include <iostream>
#include "Menu.hpp"
#include "pilas.hpp"  
using namespace std;

int main() {
    pilas* miPila = new pilas();
    Menu menu(miPila);
    menu.mostrarMenu();
    delete miPila;
    return 0;
}