#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int to;
	int dist;
};
int m, n, k, x;
vector<vector<node>> v;

bool operator<(node a, node b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}
vector<int> dist;
vector<int> used;
void dijkstra() {
	dist = vector<int>(n + 1, 2124567890);
	used = vector<int>(n + 1);
	priority_queue<node> pq;
	dist[x] = 0;
	pq.push({ x,0 });

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (used[now.to] == 1)continue;
		used[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			node ed = v[now.to][i];
			int nextnode = ed.to;
			int nextdist = ed.dist;

			if (dist[nextnode] <= dist[now.to])continue;
			dist[nextnode] = dist[now.to] + nextdist;
			pq.push({ nextnode, dist[nextnode] });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> x;
	v = vector <vector<node>>(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back({ to, 1 });
	}

	dijkstra();

	int flag = 1;
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == k) {
			flag = 0;
			break;
		}
	}
	
	if (flag)cout << -1;
	else {
		for (int i = 0; i < dist.size(); i++) {
			if (dist[i] == k) {
				cout << i << "\n";
			}
		}
	}
}