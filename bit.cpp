#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int bit[N];

void update(int i, int val) {
	while (i < N) {
		bit[i] += val;
		i += (i&-i);
	}
}

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

int main() {
		

	return 0;
}