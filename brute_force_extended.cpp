/*
Codigo original de geeksforgeeks.org
solo se agrego la operacion de transposicion
*/

#include <bits/stdc++.h>
using namespace std;

int levenshteinRecursive(const string& S1, const string& S2, int m, int n, vector<int> costos)
{
    // S1 is empty
    if (m == 0) {
        return n * costos[0];
    }
    // S2 is empty
    if (n == 0) {
        return m * costos[1];
    }

    if (S1[m - 1] == S2[n - 1]) {
        return levenshteinRecursive(S1, S2, m - 1, n - 1, costos);
    }


    int insertion = levenshteinRecursive(S1, S2, m, n - 1, costos) + costos[0];   // insertion
    int remove = levenshteinRecursive(S1, S2, m - 1, n, costos) + costos[1];      // remove
    int replace = levenshteinRecursive(S1, S2, m - 1, n - 1, costos) + costos[2]; // replace

    // Se calcula el costo de la transposición si es posible
    int transposition = INT_MAX;
    if (m > 1 && n > 1 && S1[m - 1] == S2[n - 2] && S1[m - 2] == S2[n - 1]) {
        transposition = levenshteinRecursive(S1, S2, m - 2, n - 2, costos) + costos[3]; // transposition
    }

    return min({insertion, remove, replace, transposition});
}

// Drivers code
int main() {
    // Se definen los costos de la forma: {insertar, remover, reemplazar, transponer}
    vector<int> costos = {1, 1, 1, 1};
    int j = 11;
    for (int i = 1; i < 5; i++) {
        string arch_2 = to_string(j);
        arch_2 += ".txt";
        j += 11;
        ofstream second_file(arch_2);
        char num[3];
        snprintf(num, sizeof(num), "%02d", i);
        string arch = num;
        arch += ".txt";
        //second_file << "Archivo: " << arch << endl;

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
                    //cout << "S1: " << S1 << " S2: " << S2 << endl;
                    auto start = std::chrono::system_clock::now();
                    int edit_distance = levenshteinRecursive(S1, S2, S1.length(), S2.length(), costos);
                    auto end = std::chrono::system_clock::now();
                    chrono::duration<float, milli> duration = end - start;
                    second_file << edit_distance << " " << duration.count() << endl;
                }
            }
        } else {
            cout << "No se pudo abrir el archivo: " << arch << endl;
        }
        file.close();
        second_file.close();
        cout<<"Archivo "<<arch_2<<" listo :3"<<endl;
    }

    return 0;
}
