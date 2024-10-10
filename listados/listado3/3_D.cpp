//3_D
//veci,, usar un vecor y crear todas las combinaciones posibles con los elementos del num,,
//se ordenan se menor a mayopr y luego se consulta el primero

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string numero = to_string(n);
    vector<char> num;
    vector<vector<char>> permutaciones;
    for (int i = 0; i < numero.length(); i++){
        num.push_back(numero[i]);
    }
    do {
        vector<char> aux;
        for (auto i: num) aux.push_back(i);
        permutaciones.push_back(aux);
    } while (next_permutation(num.begin(), num.end()));
    
    sort(permutaciones.begin(), permutaciones.end());

    int cant = permutaciones.size();
    if (cant == 1){
        cout<<0<<endl;
    } else {
        for (int i = 0; i < permutaciones[cant-2].size(); i++){
            cout<<permutaciones[cant-2][i];
        }
    }

    return 0;
}