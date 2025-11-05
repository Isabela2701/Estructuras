#include <iostream>

using namespace std;

class Abuelo{

    int edad;
     public:
     void mimarAbuelo(){
        cout<<"Los abuelitos miman a sus nietos"<<endl;
     }
};

class Papa:public Abuelo{
    int numeroHijos;
    public:
    void mimarPapa(){
        cout<<"Los papas miman a sus hijos"<<endl;
    }
};

class Hijo:public Papa{
    bool genero;
    public:
    void mimar(){
        cout<<"Los nietos son mimados por sus abuelitos y papas"<<endl;
    }
};


int main (){
    Papa papa1;
    Hijo hijo1;

    hijo1.mimarAbuelo();

}