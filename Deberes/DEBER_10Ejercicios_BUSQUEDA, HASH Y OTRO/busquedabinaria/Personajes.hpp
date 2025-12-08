#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP
#include <string>
#include <iostream>
using namespace std;

class Pokemons{
    private:
    string nombre;
    int posicion;

    public:
    Pokemons(string Nombre, int Posicion){
        nombre=Nombre;
        posicion=Posicion;
    }

    Pokemons(){
    }
    
    void setNombre(string Nombre){
        nombre=Nombre;
    }
    void setPosicion(int Posicion){
        posicion=Posicion;
    }

    void imprimirPokemons(){
        cout<<"Nombre del personaje: "<<nombre<<endl;
        cout<<"Posicion: "<<posicion<<endl;
    }

    string getNombre(){
        return nombre;
    }
    
    int getPosicion(){
        return posicion;
    }
};
#endif