#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void QuickSort(vector<int> V){
    int a = V.size()/2;
    cout<<V[a]<<endl;
}

int main(){
    auto start = high_resolution_clock::now();
    vector<int> abc = {1, 2, 3, 4, 5, 6, 7};
    QuickSort(abc);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"tiempo: "<<duration.count();

    return 0;
}