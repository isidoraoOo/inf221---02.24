/*
Codigo original de geeksforgeeks.org
solo se agrego la operacion de transposicion
*/

#include <bits/stdc++.h>
using namespace std;

int levenshteinRecursive(const string& S1, const string& S2, int m, int n)
{
    // S1 is empty
    if (m == 0) {
        return n;
    }
    // S2 is empty
    if (n == 0) {
        return m;
    }

    if (S1[m - 1] == S2[n - 1]) {
        return levenshteinRecursive(S1, S2, m - 1, n - 1);
    }

    int insertion = levenshteinRecursive(S1, S2, m, n - 1);
    int remove = levenshteinRecursive(S1, S2, m - 1, n);
    int replace = levenshteinRecursive(S1, S2, m - 1, n - 1);

    // Se calcula el costo de transposición si es posible
    int transposition = INT_MAX;
    if (m > 1 && n > 1 && S1[m - 1] == S2[n - 2] && S1[m - 2] == S2[n - 1]) {
        transposition = levenshteinRecursive(S1, S2, m - 2, n - 2);
    }

    return 1 + min({insertion, remove, replace, transposition});
}

// Drivers code
int main() {
    string S1 = "intention";
    string S2 = "execution";

    // Function Call
    int distance = levenshteinRecursive(S1, S2, S1.length(), S2.length());
    cout << "Levenshtein Distance (including Transposition): " << distance << endl;
    return 0;
}
