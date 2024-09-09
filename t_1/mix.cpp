// Todo junto
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void crear_arch(int n){
    ofstream archivo("matrices.txt");
    cout << "Orden: " << endl;
    cin >> n;

    archivo << "A " << n << " " << n;
    archivo << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = rand() % 1000;
            archivo << a << " ";
        }
        archivo << "\n";
    }

    archivo << "B " << n << " " << n;
    archivo << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int b = rand() % 1000;
            archivo << b << " ";
        }
        archivo << "\n";
    }
    
    archivo.close();
}

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

int main(){
    int a;
    cout<<"Iteraciones: ";
    cin>>a;  

    ofstream file("tiempos.txt");
    int j = 0;
    file << "Tiempos de ejecucion\n";
    file << "Orden\n";
    while (j < a){
        file << pow(2, j) << "x" << pow(2, j) << ": ";
        int g = pow(2, j);
        crear_arch(g);
        ifstream archivo("matrices.txt");

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
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << duration.count() <<"\n";

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
        for (int i = 0; i < filas; i++) {
            delete[] a[i];
            delete[] b[i];
            delete[] c[i];
        }
        delete[] a;
        delete[] b;
        delete[] c;

        int status = remove("matrices.txt");
        j+=1;
    }
    file.close();
    return 0;
}