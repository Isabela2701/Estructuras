#include <iostream>

using namespace std;

int main (){

    int x;
    char palabra;
    bool girar;
    float y;
    double n;
    string alpha;

    cout<<sizeof(x)<<endl;
    cout<<sizeof(palabra)<<endl;
    cout<<sizeof(girar)<<endl;
    cout<<sizeof(y)<<endl;
    cout<<sizeof(n)<<endl;
    cout<<sizeof(alpha)<<endl;

    string alimento="Hamburguesa";
    string &comida=alimento;

    cout<<alimento<<endl;
    cout<<comida<<endl;

    alimento="Hot dog";
    cout<<alimento<<endl;
    cout<<comida<<endl;


    string food="Pizza";
    cout<<food<<endl;
    cout<<&food<<endl;

    string* ptr;
    ptr=&food;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;


    double salario;
    salario=300.50;

    double* ptr1= &salario;

    cout<<"Salario: "<<*ptr1<<endl;
    cout<<"Memoria salario "<<ptr1<<endl;
    cout<<"Valor de la variable double "<<salario<<endl;

    salario=50.20;
    cout<<"Salario: "<<*ptr1<<endl;
    cout<<"Memoria salario "<<ptr1<<endl;
    cout<<"Valor de la variable double "<<salario<<endl;

    *ptr1=59.5;
    cout<<"Salario: "<<*ptr1<<endl;
    cout<<"Memoria salario "<<ptr1<<endl;
    cout<<"Valor de la variable double "<<salario<<endl;
}