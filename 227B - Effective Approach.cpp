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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

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

#define wl(a) while(a--)
#define FORCINNM(lim,arr) for(int i=0;i<lim;++i){cin>>arr[i];}
#define FORCINPB(lim,arr) for(int i=0,t;i<lim;++i){cin>>t;arr.push_back(t);}

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
	int arrlen, querlen, q;
	//stoe = vasya, etos = petya
	ull stoe(0), etos(0);
	cin >> arrlen;
	unordered_map<int, int> arr;
	for (int i = 1,val; i <= arrlen; i++) {
		cin >> val;
		arr.insert({ val,i });
	}
	cin >> querlen;
	for (int i = 0, q; i < querlen; i++) {
		cin >> q;
		stoe += arr[q];
		etos += arrlen - arr[q] + 1;
	}
	cout << stoe << ' ' << etos;
}