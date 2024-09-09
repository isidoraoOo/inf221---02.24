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

void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;

    ofstream file("tiempos MergeSort desordenados.txt");
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
        mergeSort(V, 0, a-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << a << ": " << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";
        remove("vector.txt");
    }
    file.close();
    return 0;
}