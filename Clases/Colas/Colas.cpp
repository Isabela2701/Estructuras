#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<string> cities;

    cout << "¿La cola esta vacia? " << cities.empty() << endl;

    cities.push("Quito");
    cities.push("Guayaquil");
    cities.push("Cuenca");

    cout << "Tamano de la cola: " << cities.size() << endl;

    cout << "Primero en la cola: " << cities.front() << endl;
    cout << "Ultimo en la cola: " << cities.back() << endl;

    cities.pop();
    cout << "Primero ahora: " << cities.front() << endl;

    cout << "Tamano actualizado: " << cities.size() << endl;

    cout << "¿La cola esta vacia? " << cities.empty() << endl;
}



