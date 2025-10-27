#include <iostream>
#include <functional>
using namespace std;

void encerrar(int ***&mat, int &p, int &f, int &c) {
    mat = (int***)malloc(p * sizeof(int**));
    for(int i=0; i<p; i++) {
        *(mat + i) = (int**)malloc(f * sizeof(int*));
        for(int j=0; j<f; j++) {
            *(*(mat + i) + j) = (int*)malloc(c * sizeof(int));
        }
    }
}

void ingresar(int ***&mat, int &p, int &f, int &c) {
    for(int k=0; k<p; k++) {
        for(int i=0; i<f; i++) {
            for(int j=0; j<c; j++) {
                cout << "Elemento [" << k << "][" << i << "][" << j << "]: ";
                cin >> *(*(*(mat + k) + i) + j);
            }
        }
    }
}

int main() {
    int p, f, c;
    cout << "Profundidad: "; cin >> p;
    cout << "Filas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
    
    int ***mat;
    encerrar(mat, p, f, c);
    ingresar(mat, p, f, c);
    
    // VERSIÓN CORREGIDA CON RECURSIÓN MÚLTIPLE
    function<int(int, int, int)> multiple1Corregido = [&](int k, int i, int j) -> int {
        if(k >= p) return 0;
        if(i >= f) return 0;
        if(j >= c) return 0;
        
        int actual = *(*(*(mat + k) + i) + j);
        
        // Tres direcciones recursivas que cubren espacios disjuntos
        int derecha = multiple1Corregido(k, i, j + 1);      // Todas las columnas a la derecha
        int abajo = multiple1Corregido(k, i + 1, j);        // Todas las filas abajo
        int profundo = multiple1Corregido(k + 1, i, j);     // Todas las capas profundas
        
        return actual + derecha + abajo + profundo;
    };
    
    // Verificación con bucles
    int sumaVerificacion = 0;
    for(int k=0; k<p; k++) {
        for(int i=0; i<f; i++) {
            for(int j=0; j<c; j++) {
                sumaVerificacion += *(*(*(mat + k) + i) + j);
            }
        }
    }
    
    cout << "Multiple 1 Corregido: " << multiple1Corregido(0, 0, 0) << endl;
    cout << "Verificación con bucles: " << sumaVerificacion << endl;
    
    // Liberar memoria
    for(int k=0; k<p; k++) {
        for(int i=0; i<f; i++) {
            free(*(*(mat + k) + i));
        }
        free(*(mat + k));
    }
    free(mat);
    return 0;
}