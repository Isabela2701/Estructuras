#include <iostream>
#include "Nodo.cpp"
#include "Colas.cpp"


int main (){
    Colas cola1;


    cola1.insertarColas(30);
    cola1.insertarColas(40);
    cola1.insertarColas(50); 
    cola1.mostrarColas();
    cola1.eliminarColas();
    cola1.mostrarColas();

    std::cout<<cola1.sumarElementosCola()<<std::endl;
    std::cout<<cola1.multiplicarElementosCola()<<std::endl;

}

