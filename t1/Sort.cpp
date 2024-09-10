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
    sort(V.begin(), V.end());
    cout<<"Vector ordenado: "<<endl;
    printVector(V);
    return 0;
}
