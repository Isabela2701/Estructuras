#include <iostream>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio del vector: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> *(arr + i);
    }

    function<void(int, int&)> A, B; 
    A = [&](int i, int& res) -> void {
        if (i == n) {

            res=1;
            return;
        }
        int temp;
        B(i+1, temp);
        res= *(arr +i) * temp;
    };
    B = [&](int i, int& res) -> void {
        if (i == n){
            res=1;
            return;
        }
        int temp;
        A(i +1, temp);
        res= *(arr + i) * temp;
    };

    int resultado;
    A(0, resultado);
    cout<<"\nResultado:"<<resultado<<endl;

    delete[] arr;

}
