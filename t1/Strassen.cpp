#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

void crear_arch(int n) {
    ofstream archivo("matrices.txt");
    archivo << "A " << n << " " << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = rand() % 1000;
            archivo << a << " ";
        }
        archivo << "\n";
    }

    archivo << "B " << n << " " << n << "\n";
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

void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int** crearMatriz(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }
    return matriz;
}

void sumarMatrices(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void restarMatrices(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int split = n / 2;

    int** a00 = crearMatriz(split);
    int** a01 = crearMatriz(split);
    int** a10 = crearMatriz(split);
    int** a11 = crearMatriz(split);
    int** b00 = crearMatriz(split);
    int** b01 = crearMatriz(split);
    int** b10 = crearMatriz(split);
    int** b11 = crearMatriz(split);

    int** m1 = crearMatriz(split);
    int** m2 = crearMatriz(split);
    int** m3 = crearMatriz(split);
    int** m4 = crearMatriz(split);
    int** m5 = crearMatriz(split);
    int** m6 = crearMatriz(split);
    int** m7 = crearMatriz(split);

    int** temp1 = crearMatriz(split);
    int** temp2 = crearMatriz(split);

    // Separar matrices en submatrices
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


    sumarMatrices(a00, a11, temp1, split);
    sumarMatrices(b00, b11, temp2, split);
    strassen(temp1, temp2, m1, split);

    sumarMatrices(a10, a11, temp1, split);
    strassen(temp1, b00, m2, split);

    restarMatrices(b01, b11, temp1, split);
    strassen(a00, temp1, m3, split);

    restarMatrices(b10, b00, temp1, split);
    strassen(a11, temp1, m4, split);

    sumarMatrices(a00, a01, temp1, split);
    strassen(temp1, b11, m5, split);

    restarMatrices(a10, a00, temp1, split);
    sumarMatrices(b00, b01, temp2, split);
    strassen(temp1, temp2, m6, split);

    restarMatrices(a01, a11, temp1, split);
    sumarMatrices(b10, b11, temp2, split);
    strassen(temp1, temp2, m7, split);

    int** c00 = crearMatriz(split);
    int** c01 = crearMatriz(split);
    int** c10 = crearMatriz(split);
    int** c11 = crearMatriz(split);

    sumarMatrices(m1, m4, temp1, split);
    restarMatrices(temp1, m5, temp2, split);
    sumarMatrices(temp2, m7, c00, split);

    sumarMatrices(m3, m5, c01, split);

    sumarMatrices(m2, m4, c10, split);

    restarMatrices(m1, m2, temp1, split);
    sumarMatrices(temp1, m3, temp2, split);
    sumarMatrices(temp2, m6, c11, split);

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

int main() {
    int iteraciones;
    cout << "Iteraciones: ";
    cin >> iteraciones;

    ofstream file("tiempos_mtrx_strassen.txt");
    file << "Tiempos de ejecucion\n";
    file << "Orden\n";

    for (int j = 1; j <= iteraciones; j++) {
        file << pow(2, j) << "x" << pow(2, j) << ": ";
        int n = pow(2, j);
        crear_arch(n);

        ifstream archivo("matrices.txt");
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo!" << endl;
            return 1;
        }

        int filas, columnas;
        string nombreMatriz;

        archivo >> nombreMatriz >> filas >> columnas;
        int** A = crearMatriz(filas);
        leerMatriz(archivo, A, filas, columnas);

        archivo >> nombreMatriz >> filas >> columnas;
        int** B = crearMatriz(filas);
        leerMatriz(archivo, B, filas, columnas);

        int** C = crearMatriz(filas);

        auto start = high_resolution_clock::now();
        strassen(A, B, C, filas);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";

        liberarMatriz(A, filas);
        liberarMatriz(B, filas);
        liberarMatriz(C, filas);
        archivo.close();
        remove("matrices.txt");
    }

    file.close();
    return 0;
}
