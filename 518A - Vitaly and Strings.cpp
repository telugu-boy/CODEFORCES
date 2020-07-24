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
#include <bitset>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <string>

#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> coord;
typedef vector<int> veci;
typedef vector<coord> coords;
const int mod = 1000000007;
const int mod2 = 998244353;

bool isprime(ull n) {
	if (n % 2 == 0) {
		return n == 2;
	}
	if (n % 3 == 0) {
		return n == 3;
	}
	ull k = sqrt(n);
	for (int i = 5; i < k; i += 2) {
		if (n % k == 0) {
			return false;
		}
	}
	return n != 1;
}

string nextlexword(string word) {
	int notz = word.length() - 1;
	while (notz!=-1 && word[notz] == 'z') {
		notz--;
	}
	if (notz == 0 && word[0] == 'z') {
		return "-1";
	}
	else {
		replace(word.begin()+notz, word.end(), 'z', 'a');
		word[notz]++;
	}
	return word;
}

int main() {
	ios_base::sync_with_stdio(false);
	string first, second;
	cin >> first >> second;
	first = nextlexword(first);
	if (first == second || first == "-1") {
		cout << "No such string";
	}
	else {
		cout << first;
	}
}