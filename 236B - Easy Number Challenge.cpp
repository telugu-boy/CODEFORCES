// solutions.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> coord;
typedef vector<int> veci;
typedef vector<coord> coords;
typedef vector<coords> adjuw;
typedef vector<veci> adjuu;
constexpr int mod = 1000000007;
constexpr int mod2 = 998244353;
constexpr int mod3 = 1073741824;
constexpr double pi = 3.141592653589793238463;

#define mp make_pair
#define pb push_back

#define wl(a) while (a--)
#define FORCINNM(lim, arr)                                                     \
  for (int i = 0; i < lim; ++i) {                                              \
    cin >> arr[i];                                                             \
  }
#define FORCINPB(lim, arr)do{for(int i=0,t;i<lim;++i){cin>>t;arr.push_back(t);}}while(0);

bitset<1001> visiteddfs;

void dfs(adjuu& graph, int vertex) {
	cout << vertex << ' ';
	visiteddfs[vertex] = true;
	for (int child : graph[vertex]) {
		if (!visiteddfs[child]) {
			dfs(graph, child);
		}
	}
}

void bfs(adjuu& graph, int vertex) {
	vector<bool> visitedbfs(1000);
	queue<int> vertices;
	vertices.push(vertex);
	visitedbfs[vertex] = true;
	while (!vertices.empty()) {
		int v = vertices.front();
		cout << v << ' ';
		vertices.pop();
		for (int child : graph[v]) {
			if (!visitedbfs[child]) {
				visitedbfs[child] = true;
				vertices.push(child);
			}
		}
	}
}


bool isprime(ull n) {
	if (n % 2 == 0) {
		return n == 2;
	}
	if (n % 3 == 0) {
		return n == 3;
	}
	ull k = sqrt(n);
	for (int i = 5; i <= k; i += 2) {
		if (n % k == 0) {
			return false;
		}
	}
	return n != 1;
}

void addedge(adjuw& adj, int v1, int v2, int wt) {
	adj[v1].emplace_back(v2, wt);
	adj[v2].emplace_back(v1, wt);
}

void addedge(adjuu& adj, int v1, int v2) {
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int m = a * b * c;
	vector<int> memo(m+1);
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j += i)
			memo[j]++;
	ull s = 0;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++) {
				int p = i * j * k;
				s += memo[p];
				s %= mod3;
			}
	cout << s;
}