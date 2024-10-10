//3_B

#include <bits/stdc++.h>
using namespace std;


int manhattanDistance(int a_1, int b_1, int a_2, int b_2) {
    return abs(a_1 - a_2) + abs(b_1 - b_2);
}

int main(){

    //leer la entrada
    vector<vector<char>> V;
    for (int i = 0; i < 4; i++){
        vector<char> lol;
        for (int j = 0; j < 4; j++){
            char elem;
            cin>>elem;
            lol.push_back(elem);

        }
        V.push_back(lol);
    }

    //Buscar el elemento vacio
    int found = 0;
    int fila, columna;
    for (int i = 0; i < 4; i++){
        if (found == 0){
            fila = i;
            for (int j = 0; j < 4; j++){
                if (found == 0){
                    columna = j;
                    if (V[i][j] == '.'){
                        found = 1;
                    }
                }
            }
        }
    }
    int scatter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char elem = V[i][j];
            if (elem != '.') {
                int target_row = (elem - 'A') / 4;
                int target_col = (elem - 'A') % 4;
                scatter += manhattanDistance(i, j, target_row, target_col);
            }
        }
    }

    cout<<scatter<<endl;
    return 0;
}