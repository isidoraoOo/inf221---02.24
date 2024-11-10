/*
Codigo original de geeksforgeeks.org
solo se agrego la operacion de transposicion
*/

#include <bits/stdc++.h>
using namespace std;

int editDistDP(const string &S1, const string &S2) {

    int m = S1.length();
    int n = S2.length();

     // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Fill the known entries in dp[][]
    // If one string is empty, then answer
    // is length of the other string
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    // Fill the rest of dp[][]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1],       // insertion
                                    dp[i - 1][j],       // remove
                                    dp[i - 1][j - 1]}); // replace

                // Se calcula el costo de transposición si es posible
                if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1); // transposition
                }
            }
        }
    }

    return dp[m][n];
}

// Dirver Code
int main() {
    string S1 = "execution";
    string S2 = "intention";

    cout << "Levenshtein Distance (including Transposition): " << editDistDP(S1, S2) << endl;

    return 0;
}
