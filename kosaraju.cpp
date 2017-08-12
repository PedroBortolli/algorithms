#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int seen[N], topsort[N], k = 0;
vector <int> v[N], rev[N];

void process(int x) {
	seen[x] = 1;
	for (auto a : v[x]) {
		if (!seen[a])
			process(a);
	}
	topsort[k++] = x;
}

//each strong connected component is colored with an unique color
void dfs(int x, int color) {
	seen[x] = color;
	for (auto a : rev[x]) {
		if (!seen[a])
			dfs(a, color);
	}
}

int main() {
	int n;
	//read vector and build another vector with reverse edges
	for (int i = 1; i <= n; i++) {
		if (!seen[i])
			process(i);
	}
	memset(seen, 0, sizeof(seen));
	int color = 1;
	for (int i = k-1; i >= 0; i--) {
		if (!seen[topsort[i]]) {
			dfs(topsort[i], color);
			color++;
		}
	}

	return 0;
}