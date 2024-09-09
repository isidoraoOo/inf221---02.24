#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

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


int main(){
    int n;
    cout<<"Largo: ";
    cin>>n;
    create_file(n, 1);
    ifstream archive("vector.txt");
    int a = pow(2, n);
    vector<int> V(a);
    read_file(archive, V, a);
    archive.close();
    return 0;
}