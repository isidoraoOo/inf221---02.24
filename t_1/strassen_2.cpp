#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef vector<vector<int>> Matrix;

// Función para dividir la matriz en submatrices
void split(const Matrix& mat, Matrix& a, Matrix& b, Matrix& c, Matrix& d) {
    int r2 = mat.size() / 2;
    int c2 = mat[0].size() / 2;

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            a[i][j] = mat[i][j];           // top-left
            b[i][j] = mat[i][j + c2];      // top-right
            c[i][j] = mat[i + r2][j];      // bottom-left
            d[i][j] = mat[i + r2][j + c2]; // bottom-right
        }
    }
}

// Función para sumar dos matrices
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Función para restar dos matrices
Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Algoritmo de Strassen para multiplicar dos matrices
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // Caso base: si la matriz es 1x1
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Dividir las matrices en submatrices
    int newSize = n / 2;
    Matrix a(newSize, vector<int>(newSize));
    Matrix b(newSize, vector<int>(newSize));
    Matrix c(newSize, vector<int>(newSize));
    Matrix d(newSize, vector<int>(newSize));
    Matrix e(newSize, vector<int>(newSize));
    Matrix f(newSize, vector<int>(newSize));
    Matrix g(newSize, vector<int>(newSize));
    Matrix h(newSize, vector<int>(newSize));

    split(A, a, b, c, d);
    split(B, e, f, g, h);

    // Calcular los 7 productos de Strassen
    Matrix p1 = strassen(a, subtract(f, h));
    Matrix p2 = strassen(add(a, b), h);
    Matrix p3 = strassen(add(c, d), e);
    Matrix p4 = strassen(d, subtract(g, e));
    Matrix p5 = strassen(add(a, d), add(e, h));
    Matrix p6 = strassen(subtract(b, d), add(g, h));
    Matrix p7 = strassen(subtract(a, c), add(e, f));

    // Combinar los resultados en la matriz C
    Matrix c11 = add(subtract(add(p5, p4), p2), p6);
    Matrix c12 = add(p1, p2);
    Matrix c21 = add(p3, p4);
    Matrix c22 = subtract(subtract(add(p1, p5), p3), p7);

    // Combinar las submatrices en una matriz
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return C;
}

int main() {
    int n = 512; // Tamaño de la matriz (debe ser una potencia de 2 para el algoritmo de Strassen)
    
    // Inicialización de matrices A y B como vectores 2D
    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    // Asignar valores aleatorios a las matrices A y B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1 + rand() % 1000;
            B[i][j] = 1 + rand() % 1000;
        }
    }

    // Iniciar el conteo del tiempo
    auto start = high_resolution_clock::now();

    // Multiplicar usando Strassen
    Matrix C = strassen(A, B);

    // Detener el conteo del tiempo
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Mostrar las matrices A, B y la matriz resultante C
    cout << "Matriz A: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriz B: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriz Resultante: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Mostrar el tiempo de ejecución
    cout<<"tiempo: "<<duration.count();

    return 0;
}
