#include <bits/stdc++.h>

using namespace std;

int matriz_sub[26][26], matriz_ins[26], matriz_del[26], matriz_trans[26][26];

int costo_sub(char a,char b){
    int costo;
    costo=matriz_sub[int(a)-97][int(b)-97];
    return costo;
}

int costo_ins(char b){
    int costo;
    costo=matriz_ins[int(b)-97];
    return costo;
}

int costo_del(char a){
    int costo;
    costo=matriz_del[int(a)-97];
    return costo;
}
int costo_trans(char a, char b){
    int costo_trans;
    costo_trans=matriz_trans[int(a)-97][int(b)-97];
    return costo_trans;

}
int fb(string a, string b,int j, int z){

    if(j==0){
        return z;
    }
    if(z==0){
        return j;
    }
    if(j>1 && z>1 && a[j-1]== b[z-2] && b[z-1] == a[j-2]){
        return min(min(fb(a,b,j-2,z-2)+costo_trans(a[j-1],b[z-1]),fb(a,b,j-1,z)+costo_ins(b[z-1])),min(fb(a,b,j,z-1)+costo_del(b[z-1]),fb(a,b,j-1,z-1)+costo_sub(a[j-1],b[z-1])));
    }
    else{
        return min(fb(a,b,j-1,z)+costo_ins(b[z-1]),min(fb(a,b,j,z-1)+costo_del(b[z-1]),fb(a,b,j-1,z-1)+costo_sub(a[j-1],b[z-1])));
    }

}
int main(){
    ifstream t1("cost_transpose.txt");
    ifstream t2("cost_insert.txt");
    ifstream t3("cost_replace.txt");
    ifstream t4("cost_delete.txt");
    ifstream t5("muestras.txt");
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            t1 >> matriz_trans[i][j];
            t3 >> matriz_sub[i][j];
        }
    }
    for (int i=0; i < 26;++i){
        t2 >> matriz_ins[i];
        t4 >> matriz_del[i];
    }
    t1.close();t2.close();t3.close();t4.close();
    int cant,valor,j,z;
    t5 >> cant;
    vector<int> resultado(cant);
    string palabra1, palabra2;
    for (int i=0; i < cant; i++){
        valor=0;
        t5>> palabra1;
        t5>> palabra2;
        j=palabra1.size();
        z=palabra2.size();
        resultado[i]=fb(palabra1,palabra2,j,z);
        cout<< "El resultado de la " << i+1 << " cadena es: " << resultado[i] << endl;
    }
    t5.close();
    return 0;
}