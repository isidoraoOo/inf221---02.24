
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <cstdlib>
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


int main() {
    string nombreArchivo = "matrices.txt"; 
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    string nombreMatriz;
    int filas, columnas;
    
    archivo >> nombreMatriz >> filas >> columnas;

    int** a = new int*[filas];
    for (int i = 0; i < filas; i++) {
        a[i] = new int[columnas];
    }

    leerMatriz(archivo, a, filas, columnas);

    archivo >> nombreMatriz >> filas >> columnas;

    int** b = new int*[filas];
    for (int i = 0; i < filas; i++) {
        b[i] = new int[columnas];
    }

    leerMatriz(archivo, b, filas, columnas);

    int** c = new int*[filas];
    for (int i = 0; i < filas; i++) {
        c[i] = new int[columnas];
    }


    auto start = high_resolution_clock::now();
    Matrix_multiplication(filas, a, b, c);
    auto stop = high_resolution_clock::now();

    cout << "\nMatriz A:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz B:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz Resultante (AxB):" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < filas; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTiempo: " << duration.count() << endl;

    archivo.close();
    return 0;
}
