/*
Codigo original de geeksforgeeks.org
Se agrego la operacion de transposicion y se especificaron los costos por operacion.
*/

#include <bits/stdc++.h>
using namespace std;

int editDistDP(const string &S1, const string &S2, vector<int>& costos) {

    int m = S1.length();
    int n = S2.length();

    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the known entries in dp[][]
    // If one string is empty, then answer
    // is length of the other string
    for (int i = 0; i <= m; i++)
        dp[i][0] = i * costos[1];
    for (int j = 0; j <= n; j++)
        dp[0][j] = j * costos[0];

    // Fill the rest of dp[][]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i][j - 1] + costos[0],        // insertion
                                 dp[i - 1][j] + costos[1],       // remove
                                 dp[i - 1][j - 1] + costos[2]}); // replace
            }

            // Se calcula el costo de la transposición si es posible
            if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + costos[3]); // transposition
            }
        }
    }

    return dp[m][n];
}

// Driver code
int main() {
    // Se definen los costos de la forma: {insertar, remover, reemplazar, transponer}
    vector<int> costos = {1, 1, 1, 1};
    int j = 10;
    for (int i = 1; i < 5; i++) {
        string arch_2 = to_string(j);
        arch_2 += ".txt";
        j += 10;
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
                    int edit_distance = editDistDP(S1, S2, costos);
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
        cout<<"Archivo "<<arch<<" listo :3"<<endl;
    }

    return 0;
}
