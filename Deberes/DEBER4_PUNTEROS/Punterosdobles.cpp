#include <iostream>

int main(){

    int a=10;
    int* ptr1;
    int** ptr2;

    ptr1=&a;
    ptr2=&ptr1;

    std::cout<<"El valor de a es:"<<a<<std::endl;
    std::cout<<"Ingrese un numero: ";
    std::cin>>**ptr2;
    std:: cout << "El nuevo valor es: " << **ptr2 << std::endl;
    

}