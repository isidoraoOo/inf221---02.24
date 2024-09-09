#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

void create_file(int n, int type){
    string name = "vector " + to_string(n) + ".txt";
    ofstream file(name);
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

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;

    ofstream file("tiempos QuickSort desordenados.txt");
    file << "Tiempos de ejecucion\n";
    file << "Largo\n";

    for (int it = 1; it < n; it++){
        int a = pow(2, it);
        string name = "vector " + to_string(a) + ".txt";
        create_file(it, 1);
        ifstream archive(name);
        vector<int> V(a);
        read_file(archive, V, a);
        archive.close();
        auto start = high_resolution_clock::now();
        quickSort(V, 0, a-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << a << ": " << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";
    }
    file.close();
    return 0;
}