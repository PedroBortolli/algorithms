// Solves SPOJ - FASTFLOW - Fast Maximum Flow

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005;  // number of vertices
const ll inf = 1e15;  // set inf

struct edge {
	int from, to;
	ll c, f;
};
vector<edge> edges;
vector<int> adj[N];

void addEdge(int i, int j, ll c) {
	edges.push_back({i, j, c, 0}); adj[i].push_back(edges.size() - 1);
	edges.push_back({j, i, 0, 0}); adj[j].push_back(edges.size() - 1);
}

int turn, seen[N], dist[N], st[N];
bool bfs (int s, int t) {
	seen[t] = ++turn;
	dist[t] = 0; 
	queue<int> q({t});
	while (q.size()) {
		int u = q.front(); q.pop();
		st[u] = 0;
		for (auto e : adj[u]) {
			int v = edges[e].to;
			if (seen[v] != turn && edges[e^1].c != edges[e^1].f) {
				seen[v] = turn;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return seen[s] == turn;
}

ll dfs(int s, int t, ll f) {
	if (s == t || f == 0)
		return f;
	for (int &i = st[s]; i < adj[s].size(); i++) {
		int e = adj[s][i], v = edges[e].to;
		if (seen[v] == turn && dist[v] + 1 == dist[s] && edges[e].c > edges[e].f) {
			if (ll nf = dfs(v, t, min(f, edges[e].c - edges[e].f))) {
				edges[e].f += nf;
				edges[e^1].f -= nf;
				return nf;
			}
		}
	}
	return 0ll;
}

// max flow between nodes s and t (
ll max_flow(int src, int sink) {
	ll resp = 0ll;
	while (bfs(src, sink))
		while (ll val = dfs(src, sink, inf))
			resp += val;
	return resp;
}

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a,b,c);  // add both ways
		addEdge(b,a,c);  // add both ways
	}	
	printf("%lld\n", max_flow(1, n));
}