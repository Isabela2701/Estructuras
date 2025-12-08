/*Dada una lista de personajes de la saga de Star Wars de las que se conoce su nombre, resolver
la siguientes tareas:
a. listar los personajes ordenados alfabéticamente de manera ascendente;
b. determinar si el personaje Darth Maul está cargado y en qué posición se encuentra;
c. mostrar la información de los personajes que se encuentran antes y después de Hera Syndulla;
d. listar todos los personajes que comienzan con la letra L;
e. utilizar los métodos de ordenamiento y búsqueda más eficiente de acuerdo al tipo de dato*/
#include "Personajes.hpp"
#include "IO.hpp"
#include "sort.hpp"
#include "busqueda.hpp"
#include <iostream>

int main(void){
    
    int size = ingresarDatoTeclado<int>("Ingrese el tamanio de la lista");
    Pokemons* arrayPersonajes = crearMatriz<Pokemons>(size);
    for(int i = 0; i < size; i++){
        arrayPersonajes[i] = Pokemons(ingresarDatoTeclado<string>("Ingrese el Nombre"), i+1);
    }
    
    std::cout << "\n=== ARREGLO ORIGINAL ===" << std::endl;
    for(int i = 0; i < size; i++){
        arrayPersonajes[i].imprimirPokemons();
    }
    
    // Crear un array de punteros a Personaje
    Pokemons** arrayReferencias = new Pokemons*[size];
    for(int i = 0; i < size; i++){
        arrayReferencias[i] = &arrayPersonajes[i];
    }

    // Ordenar el array de punteros alfabéticamente por nombre
    Sort::bubbleSort(arrayReferencias, size);

    std::cout << "\n=== ARREGLO ORDENADO ALFABETICAMENTE POR NOMBRE ===" << std::endl;
    for(int i = 0; i < size; i++){
        arrayReferencias[i]->imprimirPokemons();
    }

    // Preguntar y mostrar vecinos de un nombre
    char opcion = ingresarDatoTeclado<char>("¿Desea mostrar vecinos de un nombre? (s/n)");
    if (opcion == 's' || opcion == 'S') {
        string nombreVecinos = ingresarDatoTeclado<string>("Ingrese el nombre para mostrar vecinos:");
        Busqueda::mostrarVecinos(arrayReferencias, nombreVecinos, size);
    }

    // Preguntar y listar personajes que comienzan con una letra
    opcion = ingresarDatoTeclado<char>("¿Desea listar personajes por inicial? (s/n)");
    if (opcion == 's' || opcion == 'S') {
        char letra = ingresarDatoTeclado<char>("Ingrese la letra inicial:");
        Busqueda::listarPorInicial(arrayReferencias, letra, size);
    }

    // Ejemplo de busqueda directa (opcional, ya existia)
    int indice = Busqueda::busquedaNombre(arrayReferencias, ingresarDatoTeclado<string>("Ingrese nombre a buscar: "), size);
    std::cout << "El indice encontrado es: " << indice << std::endl;
    
    // Liberar la memoria de ambos arrays
    delete[] arrayReferencias;
    delete[] arrayPersonajes;

    return 0;
}