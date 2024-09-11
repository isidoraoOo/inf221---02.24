#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void leerMatriz(ifstream& archivo, int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            archivo >> matriz[i][j];
        }
    }
}

void Transposed(int filas, int columnas, int** B, int** D){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            D[j][i] = B[i][j];
        }
    }
}

void Transposed_matrix(int filas, int columnas, int** A, int** D, int** C){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            C[i][j] = 0;
            for (int k = 0; k < columnas; k++){
                C[i][j] += A[i][k] * D[k][j];
            }
        }
    }   
}

void printMatrix(int** mtrx, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << mtrx[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string nombre;
    int filasA, columnasA, filasB, columnasB;

    cout << "Nombre del archivo a ejecutar (sin extensión): " << endl;
    getline(cin, nombre);
    string name = nombre + ".txt";

    ifstream archivo(name);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    archivo >> nombre >> filasA >> columnasA;

    int** A = new int*[filasA];
    for (int i = 0; i < filasA; i++) {
        A[i] = new int[columnasA];
    }

    leerMatriz(archivo, A, filasA, columnasA);

    archivo >> nombre >> filasB >> columnasB;

    int** B = new int*[filasB];
    for (int i = 0; i < filasB; i++) {
        B[i] = new int[columnasB];
    }

    leerMatriz(archivo, B, filasB, columnasB);

    archivo.close();

    if (columnasA != filasB) {
        cerr << "Error: El número de columnas de la matriz A debe ser igual al número de filas de la matriz B." << endl;
        return 1;
    }

    int** D = new int*[columnasB];
    for (int i = 0; i < columnasB; i++) {
        D[i] = new int[filasB];
    }

    int** C = new int*[filasA];
    for (int i = 0; i < filasA; i++) {
        C[i] = new int[columnasB];
    }

    Transposed(filasB, columnasB, B, D);
    Transposed_matrix(filasA, columnasB, A, D, C);

    cout << "Matriz A: "<<endl;
    printMatrix(A, filasA, columnasA);
    cout << "Matriz B: "<<endl;
    printMatrix(B, filasB, columnasB);
    cout << "Matriz B transpuesta: "<<endl;
    printMatrix(D, columnasB, filasB);
    cout << "Producto de las matrices: "<<endl;
    printMatrix(C, filasA, columnasB);

    for (int i = 0; i < filasA; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] C;

    for (int i = 0; i < filasB; i++) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < columnasB; i++) {
        delete[] D[i];
    }
    delete[] D;

    return 0;
}
