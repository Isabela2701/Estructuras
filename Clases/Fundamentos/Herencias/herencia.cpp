#include <iostream>

using namespace std;

class Animal{
    int peso;
    int altura;

    public:
    void emitirSonido(){
        cout<<"El animal hace un ruido"<<endl;
    }
    void esVertebrado(){
        cout<<"El animal es vertebrado"<<endl;
    }
};

class Perro:public Animal{
    int numeroPatas;
    string Raza;
    bool tienePerigri;

    public: 
    void emitirSonido(){
        cout<<"El perro hace guau gua"<<endl;
    }
};

class Gato:public Animal{
    int numeroPatas;
    string Raza;
    bool genero;

    public:
    void emitirSonido(){
        cout<<"El gato hace miau miau"<<endl;
    }
};

int main (){

    Animal* animal2;

    Animal animal1;
    animal1.emitirSonido();

    Perro perro1;
    perro1.emitirSonido();
    perro1.esVertebrado();

    Gato gato1;
    gato1.emitirSonido();

    animal2=&perro1;
    animal2->emitirSonido();
    animal2->esVertebrado();
}
