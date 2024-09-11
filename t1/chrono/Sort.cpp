#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;


void read_file(ifstream& file, vector<int>& V, int n){
    for (int i = 0; i < n; i++){
        file >> V[i];
    }
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;

    ofstream file("tiempos Sort desordenados.txt");
    file << "Tiempos de ejecucion\n";
    file << "Largo\n";

    for (int it = 1; it <= n; it++){
        int a = pow(2, it);
        string name = "vector largo " + to_string(a) + " desordenado.txt";
        ifstream archive(name);
        vector<int> V(a);
        read_file(archive, V, a);
        archive.close();
        auto start = high_resolution_clock::now();
        sort(V.begin(), V.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << a << ": " << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";
    }
    file.close();
    return 0;
}