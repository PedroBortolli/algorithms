#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, dist[N][N];

void ford() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
		

	return 0;
}