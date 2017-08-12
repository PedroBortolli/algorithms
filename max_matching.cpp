#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[205];
int match[205], seen[205];

bool check(int x) {
	for (auto a : v[x]) {
		if (!seen[a]) {
			seen[a] = 1;
			if (match[a] < 0 or check(match[a])) {
				match[a] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(match, -1, sizeof(match));
	int cont = 0;
	for (int i = 0; i < n; i++) {
		memset(seen, 0, sizeof(seen));
		if (check(i)) cont++;
	}

	//cont = numero maximo de matchings
	printf("%d\n", cont);
}