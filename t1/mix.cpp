// Todo junto
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;

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

int main(){
    int a;
    cout<<"Iteraciones: ";
    cin>>a;  

    int j = 0;
    while (j < a){
        int g = pow(2, j);
        crear_arch(g);
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

    return 0;
}