#include <iostream>
#include <fstream>
#include <cstdlib> // Para usar rand()
using namespace std;

int main() {
    ofstream archivo("matrices.txt");
    int n;
    cout << "Orden: " << endl;
    cin >> n;

    archivo << "A " << n << " " << n;
    archivo << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = rand() % 1000;
            archivo << a << " ";
        }
        archivo << "\n";
    }

    archivo << "B " << n << " " << n;
    archivo << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int b = rand() % 1000;
            archivo << b << " ";
        }
        archivo << "\n";
    }
    
    archivo.close();
    return 0;
}
