// solutions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see buil4d output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    vector<bitset<20>> binplayers;
    int n, m, k, cnt(0);
    cin >> n >> m >> k;
    for (int i = 0, t; i < m; i++) {
        cin >> t;
        binplayers.push_back(bitset<20>(t));
    }
    cin >> n;
    bitset<20> fedor(n);
    for (int i = 0; i < binplayers.size(); i++) {
        int amt = 0;
        for (int j = 0; j < 20; j++) {
            if (binplayers[i].test(j) ^ fedor.test(j)) {
                amt++;
            }
        }
        if (amt <= k) {
            cnt++;
        }
    }
    cout << cnt;
}