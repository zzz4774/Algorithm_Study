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
int n, m;
int startnode, endnode;
ll path;
vector<ll> dist;
vector<int> used;
priority_queue<edge> pq;
bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

void dijkstra() {
	dist = vector<ll>(n + 1, 982134567890);
	used = vector<int>(n + 1, 0);

	pq.push({ startnode, 0 });
	dist[startnode] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		int nownode = now.to;
		ll nowdist = now.dist;
		if (used[nownode] == 1)continue;
		used[nownode] = 1;

		for (int i = 0; i < v[nownode].size(); i++) {
			int num = v[nownode][i].to;
			ll d = v[nownode][i].dist;

			if (dist[num] <= dist[nownode] + d)continue;
			dist[num] = dist[nownode] + d;
			pq.push({ num, dist[nownode] + d });
		}

	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v = vector<vector<edge>>(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}

	cin >> startnode >> endnode;
	dijkstra();

	cout << dist[endnode] << "\n";
}