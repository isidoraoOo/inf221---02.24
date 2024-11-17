#include <bits/stdc++.h>
using namespace std;

int matriz_sub[26][26], matriz_ins[26], matriz_del[26], matriz_trans[26][26];

int costo_sub(char a, char b) {
    return matriz_sub[int(a) - 97][int(b) - 97];
}

int costo_ins(char b) {
    return matriz_ins[int(b) - 97];
}

int costo_del(char a) {
    return matriz_del[int(a) - 97];
}

int costo_trans(char a, char b) {
    return matriz_trans[int(a) - 97][int(b) - 97];
}

int DP(string a, string b, int j, int z){
    vector<vector<int>> matriz(j+1, vector<int>(z+1));
    int min_1, min_2;
    for (int i = 0; i < j+1; i++){
        for (int v = 0; v < z+1; v++){
            if(i == 0 && v == 0){
                matriz[i][v]=0;
            }
            else if(i==0){
                matriz[i][v] = v;
            }
            else if(v==0){
                matriz[i][v] = i;
            }
            else if(i > 1 && v > 1 && a[i-1] == b[v-2] && b[v-1] == a[i-2]){
                min_1 = min(matriz[i-1][v-1] + costo_sub(a[i-1], b[v-1]),matriz[i][v-1] + costo_ins(b[v-1]));
                min_2 = min(matriz[i-1][v] + costo_ins(a[i-1]), matriz[i-2][v-2] + costo_trans(a[i-1], b[v-1]));
                matriz[i][v]=min(min_1, min_2);
            }
            else{
                min_1 = min(matriz[i-1][v-1] + costo_sub(a[i-1], b[v-1]),matriz[i][v-1] + costo_ins(b[v-1]));
                min_2 = matriz[i-1][v]+ costo_ins(a[i-1]);
                matriz[i][v]=min(min_1, min_2);
            }
        }
    }
    return matriz[j][z];
}

int main() {
    ifstream file_1("cost_transpose.txt");
    ifstream file_2("cost_insert.txt");
    ifstream file_3("cost_replace.txt");
    ifstream file_4("cost_delete.txt");

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            file_1 >> matriz_trans[i][j];
            file_3 >> matriz_sub[i][j];
        }
    }
    for (int i = 0; i < 26; ++i) {
        file_2 >> matriz_ins[i];
        file_4 >> matriz_del[i];
    }

    file_1.close();
    file_2.close();
    file_3.close();
    file_4.close();

    int j = 21;
    for (int i = 1; i < 5; i++) {
        string arch_2 = to_string(j);
        arch_2 += ".txt";
        j += 1;
        ofstream data_file(arch_2);
        char num[3];
        snprintf(num, sizeof(num), "%02d", i);
        string arch = num;
        arch += ".txt";

        ifstream file(arch);
        if (file) {
            string line, palabra, S1, S2;
            while (getline(file, line)) {
                vector<string> cadenas;
                stringstream ss(line);
                while (ss >> palabra) {
                    cadenas.push_back(palabra);
                }
                if (!line.empty()) {
                    if (line[0] == ' ') {
                        //palabra 1 vacia
                        S1 = "";
                        S2 = cadenas.empty() ? "" : cadenas[0];
                    } else {
                        if (cadenas.size() > 1) {
                            // 2 palabras
                            S1 = cadenas[0];
                            S2 = cadenas[1];
                        } else {
                            // palabra 2 vacia
                            S1 = cadenas[0];
                            S2 = "";
                        }
                    }
                    auto start = std::chrono::system_clock::now();
                    int largo = max(S1.length(), S2.length());
                    int edit_distance = DP(S1, S2, S1.length(), S2.length());
                    auto end = std::chrono::system_clock::now();
                    chrono::duration<float, milli> duration = end - start;
                    data_file << largo << " " << edit_distance << " " << duration.count() << endl;
                }
            }
        } else {
            cout << "No se pudo abrir el archivo: " << arch << endl;
        }
        file.close();
        data_file.close();
        cout<<"Archivo "<<arch_2<<" listo :3"<<endl;
    }
    return 0;
}