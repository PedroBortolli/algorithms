// finds min dist from node 1 to node n
void djik() {
	priority_queue<pair <int, int> > s;
	s.push({0, 1});
	dist[1] = 0;
	while (!s.empty()) {
		ll f = s.top().second, x = -(s.top().first);
		s.pop();
		if (f == n) return;
		if (x != dist[f]) continue;
		for (ll a : v[f]) {
			if (dist[f]+c[{f,a}] < dist[a]) {
				dist[a] = dist[f]+c[{f,a}];
				s.push({-(dist[a]), a});
			}
		}
	}
}
