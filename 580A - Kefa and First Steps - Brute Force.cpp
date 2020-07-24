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
using namespace std;

int main() {
	vector<int> days;
	int amt,posmax(0),maxlen(0);
	cin >> amt;
	for (int i = 0,t; i < amt; i++) {
		cin >> t;
		days.push_back(t);
	}
	for (int i = 0; i < days.size()-1; i++) {
		if (days[i] <= days[i + 1]) {
			posmax++;
		}
		else {
			if (posmax > maxlen) {
				maxlen = posmax;
			}
			posmax = 0;
		}
	}
	if (posmax > maxlen) {
		maxlen = posmax;
	}
	cout << maxlen+1 << endl;
}