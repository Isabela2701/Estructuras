#include "CLASES.H"
#include <iostream>
using namespace std;

int main() {
CLASES clase (5, 3.5f, 4.25, 'A', 100000L, 10);
cout<<"Tamanio de int: "<<sizeof(int)<<" bytes"<<endl;
cout<<"Tamanio de float: "<<sizeof(float)<<" bytes"<<endl;  
cout<<"Tamanio de double: "<<sizeof(double)<<" bytes"<<endl;
cout<<"Tamanio de char: "<<sizeof(char)<<" bytes"<<endl;
cout<<"Tamanio de long int: "<<sizeof(long int)<<" bytes"<<endl;
cout<<"Tamanio de short int: "<<sizeof(short int)<<" bytes"<<endl;
cout<<"Suma de todos los tamanos: "<<sizeof(int)+sizeof(float)+sizeof(double)+sizeof(char)+sizeof(long int)+sizeof(short int)<<" bytes"<<endl;
cout<<"Tamanio total de objeto: "<<sizeof(clase)<<" bytes"<<endl;

}