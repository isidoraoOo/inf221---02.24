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

    int* list = new int[a];
    int largo = sizeof(list) / sizeof(list[0]);
    read_file(archive, list, a);
    archive.close();
    selectionSort(list, a);
    cout<<"Vector inicial: "<<endl;
    printArray(list, a);
    sort(V.begin(), V.end());
    cout<<"Vector ordenado: "<<endl;
    printArray(list, a);
    delete[] list;
    return 0;
}
