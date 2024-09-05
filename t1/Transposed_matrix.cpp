#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Transposed(int n, int** B, int** D){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            D[i][j] = B[j][i];
        }
    }
}

void Transposed_matrix(int n, int** A, int** C, int** D){
     for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int k = 0; k < n; k++){
                C[i][j] +=  A[i][k] * D[j][k];
            }
        }
    }   
}
int main(){

    int n = 512;
    int** a = new int*[n];
    int** b = new int*[n];
    int** c = new int*[n];
    int** d = new int*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];
        d[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1+ rand() % 1000;
            b[i][j] = 1+ rand() % 1000;
        }
    }
    Transposed(n, b, d);
    auto start = high_resolution_clock::now();
    Transposed_matrix(n, a, c, d);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<endl;

    cout<<"Matriz A: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Matriz B: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout<<"Matriz B transpuesta: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Matriz Resultante: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;


    cout<<"tiempo: "<<duration.count();
    return 0;    
}
