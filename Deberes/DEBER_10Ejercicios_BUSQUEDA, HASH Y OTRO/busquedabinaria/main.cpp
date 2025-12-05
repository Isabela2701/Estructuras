#include "Personajes.hpp"
#include "IO.hpp"
#include <iostream>
#include <string>

int main(){
    int size=ingresarDatoTeclado<int>("Ingrese el tamanio de la lista: ");
    Personaje* arrayPersonajes=crearMatriz<Personaje>(size);

    for(int i=0; i<size;i++){
        
        arrayPersonajes[i]=Personaje(ingresarDatoTeclado<string>("Ingrese el nombre: "),  
                            i+1);
    }

    for(int i=0;i<size;i++){
        arrayPersonajes[i].imprimirPersonaje();
    }
    


}