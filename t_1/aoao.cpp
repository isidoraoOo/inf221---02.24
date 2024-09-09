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

int main() {
    int iteraciones;
    cout << "Iteraciones: ";
    cin >> iteraciones;  

    ofstream file("tiempos mtrx convencional.txt");
    file << "Tiempos de ejecucion\n";
    file << "Orden\n";
    
    for (int j = 1; j <= iteraciones; j++) {
        int a = pow(2, j); 
        string name = "matriz orden " + to_string(a) + "x" + to_string(a) + ".txt";
        cout<<name<<endl;
        file << a << "x" << a << ": ";

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

        auto start = high_resolution_clock::now();
        Matrix_multiplication(filas, A, B, C);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";

        for (int i = 0; i < filas; i++) {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;

        archivo.close();
    }

    file.close();
    return 0;
}