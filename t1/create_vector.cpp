// archivos vectores

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void create_file(int n, int type){
    int a = pow(2, n);
    string name = "vector largo " + to_string(a) + " ordenado.txt";
    ofstream file(name);
    int j = 0;
    if (type == 0){
        while (j < a){
            file << j << " ";
            j+=1;
        }
    }
    if (type == 1){
        while (j < a){
            int a = 1 + rand() % 1000;
            file << a << " ";
            j+=1;
        }
    }
    file.close();
}

int main(){
    int n;
    cout<<"Iteraciones: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        create_file(i+1, 0);
    }
    return 0;
}