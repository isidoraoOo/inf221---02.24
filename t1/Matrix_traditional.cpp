//nueva matriz tradicional

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

void leerMatriz(ifstream& archivo, int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            archivo >> matriz[i][j];
        }
    }
}

void Matrix_multiplication(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int** mtrx, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string nombre;
    int a;

    cout << "Nombre del archivo a ejecutar: " << endl;
    getline(cin, nombre);
    string name = nombre + ".txt";


    cout << "Orden de la matrix: " << endl;
    cin >> a;
    

    ifstream archivo(name);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    string nombreMatriz;
    int filas, columnas;
        
    archivo >> nombreMatriz >> filas >> columnas;

    int** A = new int*[filas];
    for (int i = 0; i < filas; i++) {
        A[i] = new int[columnas];
    }

    leerMatriz(archivo, A, filas, columnas);

    archivo >> nombreMatriz >> filas >> columnas;

    int** B = new int*[filas];
    for (int i = 0; i < filas; i++) {
        B[i] = new int[columnas];
    }

    leerMatriz(archivo, B, filas, columnas);

    int** C = new int*[filas];
    for (int i = 0; i < filas; i++) {
        C[i] = new int[columnas];
    }

    Matrix_multiplication(filas, A, B, C);
    archivo.close();

    cout << "Matriz A: "<<endl;
    printMatrix(A, a);
    cout << "Matriz B: "<<endl;
    printMatrix(B, a);
    cout << "Producto de las matrices: "<<endl;
    printMatrix(C, a);
    
    for (int i = 0; i < filas; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
