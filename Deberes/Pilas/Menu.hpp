#ifndef MENU_HPP
#define MENU_HPP

#include "pilas.hpp"  

class Menu {
private:
    pilas* pila;
public:
    Menu(pilas* pilaNueva);
    void mostrarMenu();
    void pushElemento();
    void popElemento();
    void peekElemento();
    void editarTop();
    void imprimirPila();
    int obtenerEntero(const char* mensaje);
};

#endif