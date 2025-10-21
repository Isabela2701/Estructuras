#include <iostream>

int main(){
int a=6;
int b=11;
int* p;
p=&a;
int** ptr;
std::cout<<"a:\n "<<a<<std::endl;
*ptr = p;
**ptr=10;
std::cout<<"a:\n  "<<a<<std::endl;

*p=5;
std::cout<<"a:\n  "<<a<<std::endl;

p=&b;

std::cout<<"a:\n  "<<**ptr<<std::endl;


std::cout<<"&p: "<<&p<<std::endl;
std::cout<<"p: "<<p<<std::endl;
std::cout<<"ptr:  "<<ptr<<std::endl;
std::cout<<"*p "<<*p<<std::endl;
std::cout<<"*ptr "<<*ptr<<std::endl;
std::cout<<"&a "<<&a<<std::endl;
std::cout<<"**ptr "<<**ptr<<std::endl;
}

