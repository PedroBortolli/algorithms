#include <bits/stdc++.h>
using namespace std;

long long exp(long long n, long long e, long long m) {
	if (!e) return 1ll;
	else {
		long long t = exp(n, e>>1, m);
		if (e & 1) return (n*t*t)%m;
		else return (t*t)%m;
	}
}

int main() {

	return 0;
}