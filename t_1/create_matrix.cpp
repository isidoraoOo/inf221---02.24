// files matrices cuadradas
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void create_file(int n) {
    int n_2 = pow(2, n);
    string name = "matriz orden " + to_string(n_2) + "x" + to_string(n_2) + ".txt";
    ofstream file(name);
    file << "A " << n_2 << " " << n_2 << "\n";
    for (int i = 0; i < n_2; i++) {
        for (int j = 0; j < n_2; j++) {
            int a = rand() % 1000;
            file << a << " ";
        }
        file << "\n";
    }

    file << "B " << n_2 << " " << n_2 << "\n";
    for (int i = 0; i < n_2; i++) {
        for (int j = 0; j < n_2; j++) {
            int b = rand() % 1000;
            file << b << " ";
        }
        file << "\n";
    }
    
    file.close();
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        create_file(i+1);
    }
    return 0;
}