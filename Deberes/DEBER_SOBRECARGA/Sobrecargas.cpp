#include <iostream>
#include <typeinfo>  // Para mostrar el tipo de dato
using namespace std;

// Función para mostrar el tipo de dato
template<typename T>
const char* getTypeName() {
    return typeid(T).name();
}

// Sobrecarga de funciones para diferentes combinaciones

// 1. int + int + int
int sumar(int a, int b, int c) {
    cout << "Función: int + int + int" << endl;
    return a + b + c;
}

// 2. double + double + double
double sumar(double a, double b, double c) {
    cout << "Función: double + double + double" << endl;
    return a + b + c;
}

// 3. float + float + float
float sumar(float a, float b, float c) {
    cout << "Función: float + float + float" << endl;
    return a + b + c;
}

// 4. int + int + double
double sumar(int a, int b, double c) {
    cout << "Función: int + int + double" << endl;
    return a + b + c;
}

// 5. int + double + int
double sumar(int a, double b, int c) {
    cout << "Función: int + double + int" << endl;
    return a + b + c;
}

// 6. double + int + int
double sumar(double a, int b, int c) {
    cout << "Función: double + int + int" << endl;
    return a + b + c;
}

// 7. int + int + float
float sumar(int a, int b, float c) {
    cout << "Función: int + int + float" << endl;
    return a + b + c;
}

// 8. int + float + int
float sumar(int a, float b, int c) {
    cout << "Función: int + float + int" << endl;
    return a + b + c;
}

// 9. float + int + int
float sumar(float a, int b, int c) {
    cout << "Función: float + int + int" << endl;
    return a + b + c;
}

// 10. double + double + int
double sumar(double a, double b, int c) {
    cout << "Función: double + double + int" << endl;
    return a + b + c;
}

// 11. double + int + double
double sumar(double a, int b, double c) {
    cout << "Función: double + int + double" << endl;
    return a + b + c;
}

// 12. int + double + double
double sumar(int a, double b, double c) {
    cout << "Función: int + double + double" << endl;
    return a + b + c;
}

// 13. float + float + int
float sumar(float a, float b, int c) {
    cout << "Función: float + float + int" << endl;
    return a + b + c;
}

// 14. float + int + float
float sumar(float a, int b, float c) {
    cout << "Función: float + int + float" << endl;
    return a + b + c;
}

// 15. int + float + float
float sumar(int a, float b, float c) {
    cout << "Función: int + float + float" << endl;
    return a + b + c;
}

// 16. double + double + float
double sumar(double a, double b, float c) {
    cout << "Función: double + double + float" << endl;
    return a + b + c;
}

// 17. double + float + double
double sumar(double a, float b, double c) {
    cout << "Función: double + float + double" << endl;
    return a + b + c;
}

// 18. float + double + double
double sumar(float a, double b, double c) {
    cout << "Función: float + double + double" << endl;
    return a + b + c;
}

// 19. float + float + double
double sumar(float a, float b, double c) {
    cout << "Función: float + float + double" << endl;
    return a + b + c;
}

// 20. float + double + float
double sumar(float a, double b, float c) {
    cout << "Función: float + double + float" << endl;
    return a + b + c;
}

// 21. double + float + float
double sumar(double a, float b, float c) {
    cout << "Función: double + float + float" << endl;
    return a + b + c;
}

// 22. int + double + float
double sumar(int a, double b, float c) {
    cout << "Función: int + double + float" << endl;
    return a + b + c;
}

// 23. int + float + double
double sumar(int a, float b, double c) {
    cout << "Función: int + float + double" << endl;
    return a + b + c;
}

// 24. double + int + float
double sumar(double a, int b, float c) {
    cout << "Función: double + int + float" << endl;
    return a + b + c;
}

// 25. double + float + int
double sumar(double a, float b, int c) {
    cout << "Función: double + float + int" << endl;
    return a + b + c;
}

// 26. float + int + double
double sumar(float a, int b, double c) {
    cout << "Función: float + int + double" << endl;
    return a + b + c;
}

// 27. float + double + int
double sumar(float a, double b, int c) {
    cout << "Función: float + double + int" << endl;
    return a + b + c;
}

// Función para mostrar información del tipo de resultado
template<typename T>
void mostrarResultado(T resultado) {
    cout << "Resultado: " << resultado << " (Tipo: " << getTypeName<T>() << ")" << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    cout << "PROGRAMA DE SOBRECARGA DE FUNCIONES PARA SUMA" << endl;
    cout << "=============================================" << endl;
    
    // Definir valores de prueba
    int i1 = 5, i2 = 10, i3 = 15;
    double d1 = 3.14, d2 = 2.71, d3 = 1.41;
    float f1 = 2.5f, f2 = 4.7f, f3 = 1.3f;
    
    // Pruebas con diferentes combinaciones
    
    cout << "\n1. Tres enteros:" << endl;
    mostrarResultado(sumar(i1, i2, i3));
    
    cout << "\n2. Tres doubles:" << endl;
    mostrarResultado(sumar(d1, d2, d3));
    
    cout << "\n3. Tres floats:" << endl;
    mostrarResultado(sumar(f1, f2, f3));
    
    cout << "\n4. int + int + double:" << endl;
    mostrarResultado(sumar(i1, i2, d1));
    
    cout << "\n5. int + double + int:" << endl;
    mostrarResultado(sumar(i1, d1, i2));
    
    cout << "\n6. double + int + int:" << endl;
    mostrarResultado(sumar(d1, i1, i2));
    
    cout << "\n7. int + int + float:" << endl;
    mostrarResultado(sumar(i1, i2, f1));
    
    cout << "\n8. float + int + int:" << endl;
    mostrarResultado(sumar(f1, i1, i2));
    
    cout << "\n9. double + double + float:" << endl;
    mostrarResultado(sumar(d1, d2, f1));
    
    cout << "\n10. float + double + double:" << endl;
    mostrarResultado(sumar(f1, d1, d2));
    
    cout << "\n11. int + double + float:" << endl;
    mostrarResultado(sumar(i1, d1, f1));
    
    cout << "\n12. float + int + double:" << endl;
    mostrarResultado(sumar(f1, i1, d1));
    
    cout << "\n13. double + float + int:" << endl;
    mostrarResultado(sumar(d1, f1, i1));
    
    // Ejemplo con valores específicos del usuario
    cout << "\n14. Ejemplo con valores específicos:" << endl;
    cout << "7 (int) + 3.5 (double) + 2.2f (float)" << endl;
    mostrarResultado(sumar(7, 3.5, 2.2f));
    
    return 0;
}