#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int p[N], w[N];

int find(int a) {
	return (p[a] == a) ? a : p[a] = find(p[a]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b=find(b))) return;
	if (w[b] > w[a]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

int main() {


	return 0;
}