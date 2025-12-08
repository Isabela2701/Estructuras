#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include "Personajes.hpp"
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
class Busqueda{
    public:
    static int busquedaNombre(Pokemons** listaBuscar,string nombreBuscar, int size){
        int izquierda=0;
        int derecha=size - 1;

        while(izquierda<=derecha){
            int mitad=izquierda+(derecha-izquierda)/2;
            if(nombreBuscar==listaBuscar[mitad]->getNombre()){
                return mitad;
            }
            if(nombreBuscar<listaBuscar[mitad]->getNombre()){
                derecha=mitad-1;
            }
            else if(nombreBuscar>listaBuscar[mitad]->getNombre()){
                izquierda=mitad+1;
            }
         }
        return -1; 
    }

    // muestra la información del personaje anterior y siguiente al nombre buscado
    static void mostrarVecinos(Pokemons** listaBuscar, const string& nombreBuscar, int size) {
        int idx = busquedaNombre(listaBuscar, nombreBuscar, size);
        if (idx == -1) {
            cout << "No se encontro el personaje: " << nombreBuscar << endl;
            return;
        }

        cout << "Personaje encontrado en indice " << idx << ":\n";
        listaBuscar[idx]->imprimirPokemons();
        cout << '\n';

        if (idx > 0) {
            cout << "Anterior:\n";
            listaBuscar[idx - 1]->imprimirPokemons();
        } else {
            cout << "No hay personaje anterior.\n";
        }

        if (idx + 1 < size) {
            cout << "Siguiente:\n";
            listaBuscar[idx + 1]->imprimirPokemons();
        } else {
            cout << "No hay personaje siguiente.\n";
        }
    }

    // lista todos los personajes cuyo nombre comienza con la letra dada (case-insensitive)
    static void listarPorInicial(Pokemons** lista, char letra, int size) {
        char objetivo = static_cast<char>(std::tolower(static_cast<unsigned char>(letra)));
        int encontrados = 0;
        for (int i = 0; i < size; ++i) {
            std::string nom = lista[i]->getNombre();
            if (!nom.empty()) {
                char primera = static_cast<char>(std::tolower(static_cast<unsigned char>(nom.front())));
                if (primera == objetivo) {
                    lista[i]->imprimirPokemons();
                    ++encontrados;
                }
            }
        }
        if (encontrados == 0) {
            cout << "No se encontraron personajes que comiencen con '" << letra << "'.\n";
        } else {
            cout << "Total encontrados: " << encontrados << '\n';
        }
    }
       
};
#endif