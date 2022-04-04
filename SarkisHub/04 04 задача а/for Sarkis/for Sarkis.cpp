#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

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
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j > i; j--)
        {
            if (v[j] % 10 < v[j - 1] % 10)
            {
                swap(v[j - 1], v[j]);
            }
        }
    }
    for (auto it = v.begin(); it < v.end(); it++) {
        fout << *it;
    }
    fin.close();
    fout.close();
}
