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
#include <climits>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> coord;
typedef vector<int> veci;
typedef vector<coord> coords;
typedef vector<coords> adjuw;
typedef vector<veci> adjuu;
const int mod = 1000000007;
const int mod2 = 998244353;

#define mp make_pair
#define pb push_back

#define wl(a) while(a--)
#define FORCINNM(lim,arr) for(int i=0;i<lim;++i){cin>>arr[i];}
#define FORCINPB(lim,arr) for(int i=0,t;i<lim;++i){cin>>t;arr.push_back(t);}

bitset<1001> visiteddfs, visitedbfs;

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
	visitedbfs[vertex] = true;
	queue<int> vertices;
	vertices.push(vertex);
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

void addedge(adjuw& adj, int v1, int v2, int wt)
{
	adj[v1].emplace_back(v2, wt);
	adj[v2].emplace_back(make_pair(v1, wt));
}

void addedge(adjuu& adj, int v1, int v2)
{
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}

list<pair<int, int> > getfactors(int num) {
	list<pair<int, int> > facs;
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i) {
			facs.emplace_back(i, num / i);
			facs.emplace_back(num / i, i);
		}
	}
	return facs;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int amt, ex, ey, cnt(0), flag(0);
	coord cur;
	string dirs;
	cin >> amt >> cur.first >> cur.second >> ex >> ey >> dirs;
	for (char a : dirs) {
		double dist = sqrt(pow((cur.first - ex), 2) + pow((cur.second - ey), 2));
		if (a == 'E') {
			double e = sqrt(pow((cur.first - ex + 1), 2) + pow((cur.second - ey), 2));
			if (e < dist) {
				cur.first++;
			}
		}
		else if (a == 'S') {
			double s = sqrt(pow((cur.first - ex), 2) + pow((cur.second - ey - 1), 2));
			if (s < dist) {
				cur.second--;
			}
		}
		else if (a == 'W') {
			double w = sqrt(pow((cur.first - ex - 1), 2) + pow((cur.second - ey), 2));
			if (w < dist) {
				cur.first--;
			}
		}
		else if (a == 'N') {
			double n = sqrt(pow((cur.first - ex), 2) + pow((cur.second - ey + 1), 2));
			if (n < dist) {
				cur.second++;
			}
		}
		cnt++;
		if (cur.first == ex && cur.second == ey) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << cnt;
	}
	else {
		cout << -1;
	}
}