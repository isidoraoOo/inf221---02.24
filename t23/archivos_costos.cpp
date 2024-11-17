#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file1("cost_replace.txt");
    ofstream file2("cost_transpose.txt");
    ofstream file3("cost_insert.txt");
    ofstream file4("cost_delete.txt");
    for (int i = 0; i < 26; i++){
        file3 << 1;
        file4 << 1;
        if (i != 25){
            file3 << " ";
            file4 << " ";
        }
        int rep = 1;
        for (int j = 0; j < 26; j++){
            file2 << 1;
            if (i == j){
                file1 << 0;
            } else {
                file1 << rep;
            }
            if (j != 25){
                file1 << " ";
                file2 << " ";
            }
            rep += 1;
        }
        file1 << endl;
        file2 << endl;
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();

    return 0;
}