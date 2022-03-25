#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int n, e;
struct edge {
	int to;
	ll dist;
};
vector<vector<edge>> v;

bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

int node1, node2;
priority_queue<edge> pq;
vector<ll> dist;
vector<int> used;
ll road1 = 0;
ll road2 = 0;

ll dijkstra(int start, int end) {
	dist = vector<ll>(n + 1, 89876546740);
	used = vector<int>(n + 1, 0);

	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		int nownode = now.to;
		ll nowdist = now.dist;
		if (used[nownode] == 1)continue;
		used[nownode] = 1;

		for (int i = 0; i < v[nownode].size(); i++) {
			int next = v[nownode][i].to;
			ll d = v[nownode][i].dist;

			if (dist[next] <= dist[nownode] + d)continue;
			dist[next] = dist[nownode] + d;
			pq.push({ next, dist[next] });
		}
	}
	return dist[end];

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> e;
	v = vector<vector<edge>>(n + 1);
	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
		v[to].push_back({ from, dist });
	}

	
	cin >> node1 >> node2;
	
	int flag1 = 1;
	int flag2 = 1;
	if (dijkstra(1, node1) == 89876546740) flag1 = 0;
	if (dijkstra(node1, node2) == 89876546740) flag1 = 0;
	if (dijkstra(node2, n) == 89876546740) flag1 = 0;
	if (dijkstra(1, node2) == 89876546740) flag2 = 0;
	if (dijkstra(node2, node1) == 89876546740) flag2 = 0;
	if (dijkstra(node1, n) == 89876546740) flag2 = 0;

	road1 = dijkstra(1, node1) + dijkstra(node1, node2) + dijkstra(node2, n);
	road2 = dijkstra(1, node2) + dijkstra(node2, node1) + dijkstra(node1, n);
		
	if (flag1 == 0 && flag2 == 0)cout << -1 << endl;
	else if (flag1 == 0)cout << road2 << endl;
	else if (flag2 == 0)cout << road1 << endl;
	else {
		if (road1 <= road2)cout << road1 << endl;
		else cout << road2 << endl;
	}
		

	
	
}