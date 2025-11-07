#include <iostream>
#include "Nodo.cpp"
#include "Colas.cpp"


int main (){
    Colas cola1;


    cola1.insertarColas(30);
    cola1.insertarColas(40);
    cola1.insertarColas(50); 
    cola1.insertarColas(7); 
    cola1.insertarColas(17); 
    cola1.insertarColas(1);
    cola1.insertarColas(2);
    std::cout<<std::endl;
    cola1.mostrarColas();
    std::cout<<std::endl;
    cola1.eliminarColas();
    cola1.mostrarColas();
    std::cout<<std::endl;

    std::cout<<cola1.sumarElementosCola()<<std::endl;
    std::cout<<cola1.multiplicarElementosCola()<<std::endl;
    std::cout<<cola1.sumarParesCola()<<std::endl;
    std::cout<<cola1.sumarImparesCola()<<std::endl;
    std::cout<<cola1.multiplicarParesCola()<<std::endl;
    std::cout<<cola1.multiplicarImparesCola()<<std::endl;
    
    cola1.mostrarImparesCola();
    std::cout<<std::endl;
    cola1.mostrarParesCola();


}

