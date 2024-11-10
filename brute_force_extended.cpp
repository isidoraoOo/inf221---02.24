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
    vector<int> costs = {1, 1, 1, 1};

    string S1 = "danlfzwoir";
    string S2 = "qsvuvwtlwc";

    // Function Call
    int distance = levenshteinRecursive(S1, S2, S1.length(), S2.length(), costs);
    cout << "Levenshtein Distance (including Transposition): " << distance << endl;

    return 0;
}
