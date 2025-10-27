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
    
    function<int(int, int, int, bool)> funcA, funcB;
    
    funcA = [&](int k, int i, int j, bool modo) -> int {
        if(k >= p) return (modo ? 0 : 1);
        if(i >= f) return funcA(k + 1, 0, 0, modo);
        if(j >= c) return funcA(k, i + 1, 0, modo);
        
        int val = *(*(*(mat + k) + i) + j);
        if(modo) {
            return val + funcB(k, i, j + 1, false);
        } else {
            return val * funcB(k, i, j + 1, true);
        }
    };
    
    funcB = [&](int k, int i, int j, bool modo) -> int {
        if(k >= p) return (modo ? 0 : 1);
        if(i >= f) return funcB(k + 1, 0, 0, modo);
        if(j >= c) return funcB(k, i + 1, 0, modo);
        
        int val = *(*(*(mat + k) + i) + j);
        if(modo) {
            return val - funcA(k, i, j + 1, false);
        } else {
            return val + funcA(k, i, j + 1, true);
        }
    };
    
    cout << "Indirecta 1: " << funcA(0, 0, 0, true) << endl;
    
    for(int k=0; k<p; k++) {
        for(int i=0; i<f; i++) {
            free(*(*(mat + k) + i));
        }
        free(*(mat + k));
    }
    free(mat);
    return 0;
}