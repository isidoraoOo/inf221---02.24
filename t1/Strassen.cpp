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

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}

void sumarMatrices(int** A, int** B, int** C, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void restarMatrices(int** A, int** B, int** C, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int split = n / 2;

    int** a00 = crearMatriz(split, split);
    int** a01 = crearMatriz(split, split);
    int** a10 = crearMatriz(split, split);
    int** a11 = crearMatriz(split, split);
    int** b00 = crearMatriz(split, split);
    int** b01 = crearMatriz(split, split);
    int** b10 = crearMatriz(split, split);
    int** b11 = crearMatriz(split, split);

    int** m1 = crearMatriz(split, split);
    int** m2 = crearMatriz(split, split);
    int** m3 = crearMatriz(split, split);
    int** m4 = crearMatriz(split, split);
    int** m5 = crearMatriz(split, split);
    int** m6 = crearMatriz(split, split);
    int** m7 = crearMatriz(split, split);

    int** temp1 = crearMatriz(split, split);
    int** temp2 = crearMatriz(split, split);

    for (int i = 0; i < split; i++) {
        for (int j = 0; j < split; j++) {
            a00[i][j] = A[i][j];
            a01[i][j] = A[i][j + split];
            a10[i][j] = A[i + split][j];
            a11[i][j] = A[i + split][j + split];

            b00[i][j] = B[i][j];
            b01[i][j] = B[i][j + split];
            b10[i][j] = B[i + split][j];
            b11[i][j] = B[i + split][j + split];
        }
    }

    sumarMatrices(a00, a11, temp1, split, split);
    sumarMatrices(b00, b11, temp2, split, split);
    strassen(temp1, temp2, m1, split);

    sumarMatrices(a10, a11, temp1, split, split);
    strassen(temp1, b00, m2, split);

    restarMatrices(b01, b11, temp1, split, split);
    strassen(a00, temp1, m3, split);

    restarMatrices(b10, b00, temp1, split, split);
    strassen(a11, temp1, m4, split);

    sumarMatrices(a00, a01, temp1, split, split);
    strassen(temp1, b11, m5, split);

    restarMatrices(a10, a00, temp1, split, split);
    sumarMatrices(b00, b01, temp2, split, split);
    strassen(temp1, temp2, m6, split);

    restarMatrices(a01, a11, temp1, split, split);
    sumarMatrices(b10, b11, temp2, split, split);
    strassen(temp1, temp2, m7, split);

    int** c00 = crearMatriz(split, split);
    int** c01 = crearMatriz(split, split);
    int** c10 = crearMatriz(split, split);
    int** c11 = crearMatriz(split, split);

    sumarMatrices(m1, m4, temp1, split, split);
    restarMatrices(temp1, m5, temp2, split, split);
    sumarMatrices(temp2, m7, c00, split, split);

    sumarMatrices(m3, m5, c01, split, split);

    sumarMatrices(m2, m4, c10, split, split);

    restarMatrices(m1, m2, temp1, split, split);
    sumarMatrices(temp1, m3, temp2, split, split);
    sumarMatrices(temp2, m6, c11, split, split);

    for (int i = 0; i < split; i++) {
        for (int j = 0; j < split; j++) {
            C[i][j] = c00[i][j];
            C[i][j + split] = c01[i][j];
            C[i + split][j] = c10[i][j];
            C[i + split][j + split] = c11[i][j];
        }
    }

    liberarMatriz(a00, split); liberarMatriz(a01, split);
    liberarMatriz(a10, split); liberarMatriz(a11, split);
    liberarMatriz(b00, split); liberarMatriz(b01, split);
    liberarMatriz(b10, split); liberarMatriz(b11, split);
    liberarMatriz(m1, split); liberarMatriz(m2, split);
    liberarMatriz(m3, split); liberarMatriz(m4, split);
    liberarMatriz(m5, split); liberarMatriz(m6, split);
    liberarMatriz(m7, split); liberarMatriz(temp1, split);
    liberarMatriz(temp2, split); liberarMatriz(c00, split);
    liberarMatriz(c01, split); liberarMatriz(c10, split);
    liberarMatriz(c11, split);
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

    int** C = new int*[filasA];
    for (int i = 0; i < filasA; i++) {
        C[i] = new int[columnasB];
    }

    strassen(A, B, C, filasA);

    cout << "Matriz A: " << endl;
    printMatrix(A, filasA, columnasA);
    cout << "Matriz B: " << endl;
    printMatrix(B, filasB, columnasB);
    cout << "Producto de las matrices: " << endl;
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

    return 0;
}
