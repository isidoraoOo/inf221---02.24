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

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    string nombre;
    int a;

    cout << "Nombre del archivo a ejecutar: " << endl;
    getline(cin, nombre);
    string name = nombre + ".txt";


    cout << "Largo del vector a ordenar: " << endl;
    cin >> a;
    

    ifstream archive(name);
    if (!archive.is_open()) {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    vector<int> V(a);
    read_file(archive, V, a);
    archive.close();
    cout<<"Vector inicial: "<<endl;
    printVector(V);
    quickSort(V, 0, a-1);
    cout<<"Vector ordenado: "<<endl;
    printVector(V);
    return 0;
}
