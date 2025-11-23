#include <iostream>
#include "Nodo.cpp" 
#include "Lista.cpp" 

int main() {
    
    Lista lista1;

    lista1.insertarListaInicio(5);
    lista1.insertarListaInicio(3); 
    lista1.insertarListaInicio(20); 
    lista1.insertarListaInicio(2); 
    lista1.insertarListaInicio(10); 
    lista1.insertarListaInicio(80);  
    lista1.insertarListaFinal(2);   
    lista1.insertarListaFinal(7);   
    lista1.insertarListaEn(15, 3);  
    
    std::cout << "Lista después de inserciones: ";
    lista1.mostrarLista(); 

    std::cout << "Tamaño: " << lista1.mostrarTamanio() << std::endl;
    std::cout << "Cabeza: " << lista1.consultarCabeza() << std::endl;
    std::cout << "Cola: " << lista1.consultarCola() << std::endl;

    std::cout << "\n--- Operaciones de Edición y Eliminación ---" << std::endl;
    lista1.editarMedios(99, 3); 
    std::cout << "Lista después de editar el 3er elemento: ";
    lista1.mostrarLista();

    lista1.eliminarListaEn(2);
    std::cout << "Lista después de eliminar el 2do elemento: ";
    lista1.mostrarLista();

    lista1.eliminarListaInicio(); 
    lista1.eliminarListaFinal();  
    std::cout << "Lista final: ";
    lista1.mostrarLista();
    
    std::cout << "\n--- Operaciones Matemáticas (Datos: 99, 2) ---" << std::endl;
    std::cout << "Suma Total: " << lista1.sumarElementosLista() << std::endl;
    std::cout << "Multiplicación Total: " << lista1.multiplicarElementosLista() << std::endl;
    
    std::cout << "Suma Pares: " << lista1.sumarParesLista() << std::endl;       
    std::cout << "Suma Impares: " << lista1.sumarImparesLista() << std::endl;   
    std::cout << "Suma Impares: " << lista1.sumarImparesRecursivo() << std::endl;   
    std::cout << "Multiplicación Pares: " << lista1.multiplicarParesLista() << std::endl;     
    std::cout << "Multiplicación Impares: " << lista1.multiplicarImparesLista() << std::endl;
    
    std::cout << "\n--- Mostrar Pares/Impares ---" << std::endl;
    lista1.mostrarParesLista();
    lista1.mostrarImparesLista();
    lista1.mostrarImparesReversaFuncional();


    std::cout << "\nLista antes de ordenar: ";
    lista1.mostrarLista();

    lista1.insertionSort();

    std::cout << "Lista ordenada: ";
    lista1.mostrarLista();

}