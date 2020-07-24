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
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	ull n, k;
	cin >> n >> k;
	ull oddtoevenbrkpnt = n % 2 == 0 ? n / 2 : n / 2 + 1;
	bool inevenrange = k > oddtoevenbrkpnt;
	if (inevenrange) {
		cout << (k - oddtoevenbrkpnt) * 2;
	}
	else {
		cout << k * 2 - 1;
	}
}