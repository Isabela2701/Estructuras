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
    
    function<int(int, int, int, int)> cola2 = [&](int k, int i, int j, int acum) -> int {
        if(k >= p) return acum;
        if(i >= f) return cola2(k + 1, 0, 0, acum);
        if(j >= c) return cola2(k, i + 1, 0, acum);
        
        int val = *(*(*(mat + k) + i) + j);
        return cola2(k, i, j + 1, acum * (val != 0 ? val : 1));
    };
    
    cout << "Cola 2 - Producto: " << cola2(0, 0, 0, 1) << endl;
    
    for(int k=0; k<p; k++) {
        for(int i=0; i<f; i++) {
            free(*(*(mat + k) + i));
        }
        free(*(mat + k));
    }
    free(mat);
    return 0;
}