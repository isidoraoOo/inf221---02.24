// Cambiarlo a Strassen recursivo

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void Strassen (int A[2][2], int B[2][2], int C[2][2]){
    int a =  A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];
    
    int e = B[0][0];
    int f = B[0][1];
    int g = B[1][0];
    int h = B[1][1];

    int p1 = a*(f - h);
    int p2 = (a+b)*h;
    int p3 = (c+d)*e;
    int p4 = d*(g-e);
    int p5 = (a+d)*(e+h);
    int p6 = (b-d)*(g+h);
    int p7 = (a-c)*(e+f);


    C[0][0] = p5 + p4 - p2 + p6;
    C[0][1] = p1 + p2;
    C[1][0] = p3 + p4;
    C[1][1] = p1 + p5 - p3 - p7;
}

int main(){
    auto start = high_resolution_clock::now();
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];
    Strassen(a, b, c);

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
