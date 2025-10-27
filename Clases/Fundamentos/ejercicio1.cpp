#include <iostream>
using namespace std;
void despedir();
void saludar2(){
    cout<<"Hola"<<endl;
}
void saludar(int hora){
    int opc=0;
    if (hora>=0&hora<12){
        opc=1;
    }
    else if (hora>=12&hora<18){
        opc=2;

    }
    else {
        opc=3;
    }

    switch (opc)
    {
    case 1:{
        cout<<"Buenos dias"<<endl;
        break;
    }
    case 2:{
        cout<<"Buenas tardes"<<endl;
        break;
    }
    case 3:{
        cout<<"Buenas noches"<<endl;

    } 
    
    default:{
        cout<<"Opcion no valida"<<endl;
         break;

    }
}
void despedir();
}

int main(){
    saludar2();
    cout<<"El rango de valores permitidos es entre 1 y 24, si deseas salir del programa ingresa el numero 0"<<endl;
    int hora;
    float x=6.2f;
    int y=10;
    double z=9.67;
    string Nombre="Isabela";
    bool j=false;

    const int numerodediasporaño=365;

    bool verificador=true;

    while(verificador){
        cout<<"Ingrese la hora actual"<<endl;
        cin>>hora;
        saludar(hora);

        if (hora==0){
            verificador=false;     
        }
    } 
    despedir();
       
}
void despedir(){
    cout<<"Adios"<<endl;
}
