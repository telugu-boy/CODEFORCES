// solutions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
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
#include <complex>
#include <tuple>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> coord;
typedef vector<int> veci;
typedef vector<coord> coords;
typedef vector<coords> adj;
const int mod = 1000000007;
const int mod2 = 998244353;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define wl(a) while(a--)
#define FORCIN(lim,arr) for(int i=0,t;i<lim;++i){cin>>t;arr.push_back(t);}

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int numppl, numregions;
	cin >> numppl >> numregions;
	//for each region
	vector<
		// all contestants in that region
		vector< 
			//contestant info
			pair<string, int> 
		>
	> contestants(numregions);
	//team of two
	vector< pair<string, string> > team(numregions);
	for (int i = 0; i < numppl; ++i) {
		string name;
		int region, score;
		cin >> name >> region >> score;
		contestants[region-1].push_back(make_pair(name, score));
	}
	for (int j = 0; j < numregions; j++) {
		auto& i = contestants[j];
		sort(i.begin(), i.end(), [&](auto& left, auto& right) {return left.s  < right.s; });
		auto contestant1 = i[i.size() - 1];
		auto contestant2 = i[i.size() - 2];
		if (i.size() == 2) {
			team[j] = make_pair(contestant1.f, contestant2.f);
			continue;
		}
		auto comparison = i[i.size() - 3];
		if (comparison.s == contestant1.s || comparison.s == contestant2.s) {
			team[j] = make_pair("", "");
		}
		else {
			team[j] = make_pair(contestant1.f, contestant2.f);
		}
	}

	for (auto i : team) {
		if (i.f == "" && i.s == "") {
			cout << '?' << '\n';
		}
		else {
			cout << i.f << ' ' << i.s << '\n';
		}
	}
}