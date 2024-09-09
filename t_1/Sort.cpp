#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

void create_file(int n, int type){
    ofstream file("vector.txt");
    int j = 0;
    if (type == 0){
        while (j < pow(2, n)){
            file << j << " ";
            j+=1;
        }
    }
    if (type == 1){
        while (j < pow(2, n)){
            int a = 1 + rand() % 1000;
            file << a << " ";
            j+=1;
        }
    }
    file.close();
}

void read_file(ifstream& file, vector<int>& V, int n){
    for (int i = 0; i < n; i++){
        file >> V[i];
    }
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;

    ofstream file("tiempos Sort estandar desordenados.txt");
    file << "Tiempos de ejecucion\n";
    file << "Largo\n";

    for (int it = 1; it < n; it++){
        create_file(it, 1);
        ifstream archive("vector.txt");
        int a = pow(2, it);
        vector<int> V(a);
        read_file(archive, V, a);
        archive.close();
        auto start = high_resolution_clock::now();
        sort(V.begin(), V.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << a << ": " << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";
        remove("vector.txt");
    }
    file.close();
    return 0;
}