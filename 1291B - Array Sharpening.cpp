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
#include <complex>

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
	ios_base::sync_with_stdio(false);
	int amt;
	cin >> amt;
	wl(amt) {
		int len, pend(0), send(0);
		veci arr;
		cin >> len;
		FORCIN(len, arr);
		//max prefix length
		for (int i = 0; i < len; i++) {
			if (arr[i] < i) {
				break;
			}
			pend = i;
		}
		//max suffix Length
		for (int i = len - 1; i >= 0; i--) {
			if (arr[i] < len-i-1) {
				break;
			}
			send = i;
		}
		//if part of prefix was inside suffix, can be done the other way around too.. if len-prefix instead of suffix
		cout << (pend >= send ? "Yes" : "No") << '\n';
		//It works. because If there is a gap, prefix and suffix does not cover it. meaning a sharpened array cannot be made
	}
}