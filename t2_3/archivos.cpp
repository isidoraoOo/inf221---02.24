// Código para crear los datasets

#include <bits/stdc++.h>
using namespace std;

void S1_empty(){
    ofstream file ("01.txt");
    srand(time(NULL));
    for (int i = 0; i < 200; i++){
        string palabra = "";
        for (int j = 0; j < 1 + rand() % 50; j++){
            char ch = 'a' + rand() % 26;
            palabra += ch;
        }
        file << " " << palabra << endl;;
    }
    file.close();
    cout<<"Archivo 1 listo :3"<<endl;

}

void S2_empty(){
    ofstream file ("02.txt");
    srand(time(NULL));
    for (int i = 0; i < 200; i++){
        string palabra = "";
        for (int j = 0; j < 1 + rand() % 50; j++){
            char ch = 'a' + rand() % 26;
            palabra += ch;
        }
        file << palabra;
        file << " " << endl;
    }
    file.close();
    cout<<"Archivo 2 listo :3"<<endl;

}

void repeated_ch(){
    ofstream file("03.txt");
    srand(time(NULL));
    for (int j = 0; j < 200; j++){
        string palabra1 = "", palabra2 = "";
        
        for (int i = 0; i < 1 + rand() % 50; i++) {
            char ch = 'a' + rand() % 2;
            palabra1 += ch;
        }

        for (int i = 0; i < 1 + rand() % 50; i++) {
            char ch = 'a' + rand() % 2;
            palabra2 += ch;
        }

        file << palabra1 << " " << palabra2 << endl;
    }
    file.close();
    cout<<"Archivo 3 listo :3"<<endl;

}


void swap(string& word, int a, int b){
    char aux = word[a];
    word[a] = word[b];
    word[b] = aux;
}

string transpose(string& word, int n){
    // n is the number of transpositions
    for (int i = 0; i < n; i++){
        int a = rand() % (word.length() - 2);
        swap(word, a, a + 1);
    }
    return word;
}

void need_transpositions(){
    ofstream file("04.txt");
    
    if (!file) {
        cout << "Error al abrir el archivo 04.txt" << endl;
        return;
    }
    
    srand(time(NULL));
    for (int j = 0; j < 200; j++){
        string palabra = "";
        
        for (int i = 0; i < 3 + rand() % 50; i++){
            char ch = 'a' + rand() % 26;
            palabra += ch;
        }
        
        int a = 1 + rand() % (palabra.length() / 2);
        string tr = palabra;
        tr = transpose(tr, a);
        file << tr << " " << palabra << endl;
    }

    file.close();
    cout<<"Archivo 4 listo :3"<<endl;
}

int main()
{
    S1_empty();
    S2_empty();
    repeated_ch();
    need_transpositions();
    return 0;
}

/*
DATASETS <
1. Cadenas vacías

1.1 Ambas vacias
S1 = ""
S2 = ""
Salida esperada = 0

1.2 S1 vacia
S1 = ""
S2 = "mariposa"
Salida esperada = 8 * (costo insercion)

1.3 S2 vacía
S1 = "Paris"
S2 = ""
Salida esperada = 50 * (costo eliminacion)

2 Caracteres repetidos

2.1
S1 = aabaa
S2 = aabbb
Salida esperada = 2 * (costo reemplazar)

3 Transposiciones necesarias

S1 = algoritmo
S2 = algoritom
Salida esperada = 1 * (costo transposicion)

*/