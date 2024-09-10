// C++ program for implementation of
// selection sort
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;


void read_file(ifstream& file, int arr[], int n){
    for (int i = 0; i < n; i++){
        file >> arr[i];
    }
}

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// This is code is contributed by rathbhupendra

int main(){
    int iteraciones;
    cout <<"Iteraciones: ";
    cin >> iteraciones;

    ofstream file("tiempos SelectionSort ordenados.txt");
    file << "Tiempos de ejecucion\n";
    file << "Largo\n";

    for (int j = 1; j <= iteraciones; j++){
        int a = pow(2, j);
        string name = "vector largo " + to_string(a) + " ordenado.txt";
        ifstream archivo(name);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo!" << endl;
            return 1;
        }

        int* list = new int[a];
        int largo = sizeof(list) / sizeof(list[0]);
        read_file(archivo, list, a);
        archivo.close();
        auto start = high_resolution_clock::now();
        selectionSort(list, a);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        file << a << ": " << duration.count() << " nanosegundos " << duration.count() / 1000 << " microsegundos " << duration.count() / 1e9 << " segundos" <<"\n";
        delete[] list;
    }
    file.close();
    return 0;
}
