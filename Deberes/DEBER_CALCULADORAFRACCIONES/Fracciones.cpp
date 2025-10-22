#include <iostream>
using namespace std;

int main() {
    double a, b, c, d;
    
    cout << "Calculadora de (a/b) * (c/d) = ac/bd" << endl;
    cout << "=====================================" << endl;
    
    // Entrada de datos
    cout << "Ingrese el valor de a: ";
    cin >> a;
    
    cout << "Ingrese el valor de b: ";
    cin >> b;
    
    cout << "Ingrese el valor de c: ";
    cin >> c;
    
    cout << "Ingrese el valor de d: ";
    cin >> d;
    
    // Verificar división por cero
    if (b == 0 || d == 0) {
        cout << "Error: No se puede dividir por cero" << endl;
        return 1;
    }
    
    // Cálculos
    double resultado1 = (a / b) * (c / d);
    double resultado2 = (a * c) / (b * d);
    
    // Mostrar resultados
    cout << "\nResultados:" << endl;
    cout << "(" << a << "/" << b << ") * (" << c << "/" << d << ") = " << resultado1 << endl;
    cout << "(" << a << "*" << c << ")/(" << b << "*" << d << ") = " << resultado2 << endl;
    cout << "ac/bd = " << resultado2 << endl;
    
    return 0;
}