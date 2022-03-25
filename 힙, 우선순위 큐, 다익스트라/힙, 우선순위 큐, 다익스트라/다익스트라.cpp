#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct edge {
	int to;
	int dist;
};
vector<vector<edge>> v;
int n, e;

bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

void input() {
	cin >> n >> e;
	v = vector<vector<edge>>(n + 1, vector<edge>());
	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to,dist });
	}
}

void dijkstra() {
	vector<int> dist(n + 1, 2134567890);
	vector<int> used(n + 1, 0);
	priority_queue<edge> pq;

	dist[0] = 0;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		int nownode = now.to;
		int nowdist = now.dist;
		if (used[nownode] == 1)continue;
		used[nownode] = 1;

		for (int i = 0; i < v[nownode].size(); i++) {
			edge ed = v[nownode][i];
			int to = ed.to;
			int d = ed.dist;

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

	int t;
	cin >> t;
	while (t--) {
		input();
		dijkstra();
	}

}