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

bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

vector<vector<edge>> v;
priority_queue<edge> pq;
vector<ll> dist;
vector<int> used;
vector<ll> each;
int n, m, x;



ll dijkstra(int start, int end) {
	dist = vector<ll>(n + 1, 21345678990);
	used = vector<int>(n + 1, 0);
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		if (used[now.to] == 1)continue;
		used[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			int next = v[now.to][i].to;
			ll d = v[now.to][i].dist;

			if (dist[next] <= dist[now.to] + d)continue;
			dist[next] = dist[now.to] + d;
			pq.push({ next, dist[next] });
		}
	}
	return dist[end];
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x;
	v = vector<vector<edge>>(n + 1);
	each = vector<ll>(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}

	for (int i = 1; i <= n; i++) {
		each[i] = dijkstra(i, x) + dijkstra(x, i);
	}

	sort(each.begin(), each.end(), greater<>());

	cout << each[0] << endl;

}