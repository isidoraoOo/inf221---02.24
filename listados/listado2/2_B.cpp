// listado 2
// B - Sort of Sorting
// SOLO USANDO LAS DOS PRIMERAS LETRAS !!!!!!!!!
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


void printVector (vector<string>& V){
    for (string elem : V){
       cout<<elem<<endl;;
    }
}

int main(){
    auto start = high_resolution_clock::now();
    vector<string> apellidos;
    while (true){
        int n;
        cin>>n;
        if (n == 0){
            break;
        }
        
        vector<string> V_num;
        V_num.reserve(n);
//cambiar el sort por un for int = 0 , i < 2
        for(int i = 0; i < n; i++){
            string nombre;
            cin>>nombre;
            V_num.push_back(nombre);            
        } 
        sort(V_num.begin(), V_num.end());
        apellidos.insert(apellidos.end(), V_num.begin(), V_num.end());
        apellidos.push_back(" ");
    }
    apellidos.pop_back();
    printVector(apellidos);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "tiempo: " << duration.count() * 1000;
    return 0;
}