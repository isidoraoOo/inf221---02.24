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

int brute_force(string a, string b, int j, int z) {
    if (j == 0) {
        int cost = z * costo_ins(b[z-1]);
        return cost;
    }
    if (z == 0) {
        int cost = j * costo_del(a[j-1]);
        return cost;
    }

    int trans = INT_MAX;
    if (j > 1 && z > 1 && a[j-1] == b[z-2] && b[z-1] == a[j-2]) {
        trans = brute_force(a, b, j - 2, z - 2) + costo_trans(a[j - 1], b[z - 1]);
    }

    int ins = brute_force(a, b, j, z-1) + costo_ins(b[z-1]);
    int del = brute_force(a, b, j-1, z) + costo_del(a[j-1]);
    int sub = brute_force(a, b, j-1, z-1) + costo_sub(a[j-1], b[z-1]);

    return min({trans, ins, del, sub});
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

    int j = 11;
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
                    int edit_distance = brute_force(S1, S2, S1.length(), S2.length());
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
