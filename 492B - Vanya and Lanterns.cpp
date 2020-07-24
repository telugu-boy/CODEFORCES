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
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int amt, streetlen;
	vector<int> points;
	cin >> amt >> streetlen;
	for (int i = 0, t; i < amt; ++i) {
		cin >> t;
		points.push_back(t);
	}
	sort(points.begin(), points.end());
	int distance = max(points[0], streetlen - points[points.size() - 1])*2;
	for (int i = 1; i < amt; ++i) {
		distance = max(distance, points[i] - points[i - 1]);
	}
	cout.precision(20);
	cout << fixed << distance/2.0 << endl;
}