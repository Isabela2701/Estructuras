#include <iostream>
#include "Nodo.cpp"
#include "Pilas.cpp"


int main (){
    Pilas pila1;


    pila1.insertarPila(30);
    pila1.insertarPila(40);
    pila1.insertarPila(50);
    std::cout<<std::endl;
    pila1.mostrarPila();
    pila1.eliminarPila();
    pila1.mostrarPila();
    std::cout<<std::endl;
    std::cout<<pila1.sumarElementospila()<<std::endl;
    std::cout<<pila1.multiplicarElementospila()<<std::endl;

}

