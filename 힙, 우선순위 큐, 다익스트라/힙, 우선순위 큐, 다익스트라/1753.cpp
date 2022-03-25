#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct edge {
	int to;
	ll dist;
};
vector<vector<edge>> v;
int n, e, start;

bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

void input() {
	cin >> n >> e >> start;
	v = vector<vector<edge>>(n + 1, vector<edge>());
	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to,dist });
	}
}
vector<ll> dist;

void dijkstra() {
	dist = vector<ll>(n + 1, 2232134567890);
	vector<int> used(n + 1, 0);
	priority_queue<edge> pq;

	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		int nownode = now.to;
		ll nowdist = now.dist;
		if (used[nownode] == 1)continue;
		used[nownode] = 1;

		for (int i = 0; i < v[nownode].size(); i++) {
			edge ed = v[nownode][i];
			int to = ed.to;
			ll d = ed.dist;

			if (dist[to] <= dist[nownode] + d)continue;
			dist[to] = dist[nownode] + d;
			pq.push({ to, dist[to] });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	dijkstra();

	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == 2232134567890)cout << "INF\n";
		else cout << dist[i] << "\n";
	}

}