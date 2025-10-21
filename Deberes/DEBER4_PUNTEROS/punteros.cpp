#include <iostream>
using namespace std;

void leerDireccion(int *num); //leerDireccion recibe un puntero, el puntero contiene una direccion de memoria NO UN NUMERO
bool reemplazarNum(int *num);

int main (void){
    bool reemplazo=false;
    int gato = 5;
    int* ptrgato = &gato;  //declaracion tipodato* NOMBREPUNTERO = &variable -> tipodato VARIABLE
    cout<<"La direccion de gato en main es: " <<&gato<<endl;
    leerDireccion(ptrgato);
    reemplazo = reemplazarNum(ptrgato);

    if(reemplazo){
        cout<<"El valor de gato es: " <<*ptrgato<<endl;
    }
    else cout << "No se cambio el valor"<<endl;
    
}

void leerDireccion(int *num){
    cout<<"La direccion en leerDireccion es: " <<num<<endl; //al imprimir el puntero se imprime la MEMORIA
}

bool reemplazarNum(int *num){
    *num=6; //el asterisco nos sirve para desreferenciar (Acceder al contentido del punto, es decir el valor de la variable al que apunta, no su direccion)
    return true;
}