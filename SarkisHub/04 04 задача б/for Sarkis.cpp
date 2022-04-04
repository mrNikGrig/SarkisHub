#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int sumNum(int n) {
    int sum = 0;
    while (n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main(){
    vector <int> v;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    while (!fin.eof()) {
        int n; fin >> n;
        v.push_back(n);
    }
    for (int i = 0; i < v.size(); i++){
        for (int j = v.size() - 1; j > i; j--){
            if (sumNum(v[j]) < sumNum(v[j - 1])){
                swap(v[j - 1], v[j]);
            }
        }
    }
    for (auto it = v.begin(); it < v.end(); it++) {
        fout << *it << "\n";
    }
    fin.close();
    fout.close();
}
