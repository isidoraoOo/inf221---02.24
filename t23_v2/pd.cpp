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
int matrizpd(string a, string b, int j, int z){
    vector<vector<int>> matriz(j+1, vector<int>(z+1));
    int min1,min2;
    for (int i=0; i< j+1; i++){
        for (int v=0; v < z+1; v++){
            if(i==0 && v==0){
                matriz[i][v]=0;
            }
            else if(i==0){
                matriz[i][v]=v;
            }
            else if(v==0){
                matriz[i][v]=i;
            }
            else if(i>1 && v>1 && a[i-1] == b[v-2] && b[v-1] == a[i-2]){
                min1=min(matriz[i-1][v-1]+ costo_sub(a[i-1],b[v-1]),matriz[i][v-1]+ costo_ins(b[v-1]));
                min2=min(matriz[i-1][v]+ costo_ins(a[i-1]),matriz[i-2][v-2]+ costo_trans(a[i-1],b[v-1]));
                matriz[i][v]=min(min1,min2);
            }
            else{
                min1=min(matriz[i-1][v-1]+ costo_sub(a[i-1],b[v-1]),matriz[i][v-1]+ costo_ins(b[v-1]));
                min2=matriz[i-1][v]+ costo_ins(a[i-1]);
                matriz[i][v]=min(min1,min2);
            }
        }
    }
    return matriz[j][z];
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
        t5>> palabra1;
        t5>> palabra2;
        j=palabra1.size();
        z=palabra2.size();
        resultado[i]=matrizpd(palabra1,palabra2,j,z);
        cout<< "El resultado de la " << i+1 << " cadena es: " << resultado[i] << endl;
    }
    t5.close();
    return 0;
}