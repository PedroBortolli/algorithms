#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2 * N];

void build() {
	for (int i = n-1; i > 0; i--)
		t[i] = t[i*2]+t[i*2+1];
}

void update(int id, int x) {
	id += n;
	t[id] = x;
	id /= 2;
	for (int i = id; i >= 1; i /= 2)
		t[i] = t[i*2]+t[i*2+1];
}

int query(int l, int r) {
	int ans = 0;
	l += n, r += n;
	while (l < r) {
		if (l%2 != 0) ans += t[l++];
		if (r%2 != 0) ans += t[--r];
		l /= 2;
		r /= 2;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
	build();
	printf("%d\n", query(3, 11));
	update(3, 5);
	printf("%d\n", query(3, 11));
	return 0;
}