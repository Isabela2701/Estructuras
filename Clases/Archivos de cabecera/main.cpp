#include "Interfaz.h"
#include <iostream>
#include "Interfaz.cpp"

using namespace std;

int main(){

    int opciones;

    bool salir= false;

    while(!salir){
    
        cout<< "Menu de opciones" << endl;
        cout<< "1. Sumar dos numeros" << endl;      
        cout<< "2. Restar dos numeros" << endl;
        cout<< "3. Multiplicar dos numeros" << endl;
        cout<< "4. Salir" << endl;
        cout<< "Ingrese una opcion: ";
        cin>> opciones;

        switch (opciones)
        {
        case 1:
        {
            double num1= ingresoNumeros<double>();
            double num2= ingresoNumeros<double>();
            double resultado= sumarNumeros<double>(num1,num2);
            mostrarResultado<double>(resultado);
            break;
        }
        case 2:
        {
            double num1= ingresoNumeros<double>();
            double num2= ingresoNumeros<double>();
            double resultado= restarNumeros<double>(num1,num2);
            mostrarResultado<double>(resultado);    
            break;

        }
        case 3:
        {   
            double num1= ingresoNumeros<double>();
            double num2= ingresoNumeros<double>();
            double resultado= multiplicarNumeros<double>(num1,num2);
            mostrarResultado<double>(resultado);
            break;
        } 
        case 4:
        {
            salir= true;
            cout<< "Saliendo del programa..." << endl;
            break;
        }   /* code */
        
        default:
        {
            cout<< "Opcion no valida, intente de nuevo" << endl; 
            break;
        }
        
    }
    
}
}