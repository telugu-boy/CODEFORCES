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
#include <string>
#include <algorithm>
using namespace std;

bool increasingcheck(vector<pair<int, int>> pairs) {
	for (int i = 0; i < pairs.size() - 1; i++) {
		if (pairs[i].first > pairs[i + 1].first || pairs[i].second > pairs[i + 1].second) {
			return false;
		}
	}
	return true;
}

string getpaths(vector<pair<int, int>> pairs) {
	string movement = "";
	pair<int, int> current_coord(0, 0);
	for (pair<int, int> coord : pairs) {
		int movement_r = coord.first - current_coord.first;
		int movement_u = coord.second - current_coord.second;
		movement += string(movement_r, 'R');
		movement += string(movement_u, 'U');
		current_coord = coord;
	}
	return movement;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		vector<pair<int, int>> coords;
		int amt;
		cin >> amt;
		for (int j = 0; j < amt; j++) {
			pair<int, int> pair;
			cin >> pair.first >> pair.second;
			coords.push_back(pair);
		}
		sort(coords.begin(), coords.end());
		if (!increasingcheck(coords)) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << getpaths(coords) << endl;
	}
}