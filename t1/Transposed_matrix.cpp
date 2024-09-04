#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Transposed_matrix(int A[2][2], int B[2][2], int C[2][2], int D[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            D[i][j] = B[j][i];
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            C[i][j] = 0;
            for (int k = 0; k < 2; k++){
                C[i][j] +=  A[i][k] * B[k][j];
            }
        }
    }
}


int main(){
    auto start = high_resolution_clock::now();
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];
    int d[2][2];
    Transposed_matrix(a, b, c, d);
    cout<<endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"tiempo: "<<duration.count();
    return 0;    
}