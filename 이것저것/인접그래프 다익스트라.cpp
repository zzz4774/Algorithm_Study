#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
struct edge {
	int to;
	int dist;
};
int n, e;
int test_case;
priority_queue<edge> pq;
bool operator<(edge left, edge right) {
	if (left.dist < right.dist)return false;
	if (left.dist > right.dist)return true;
	if (left.to < right.to)return false;
	if (left.to > right.to)return true;

	return false;
}
vector<vector<edge>> v;
int dis[1001];
int used[1001];


void dijkstra() {
	vector <int> dis(n + 1, 48574854);
	vector<int> used(n + 1, 0);

	pq.push({ 0,0 });
	dis[0] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (used[now.to] == 1)continue;
		used[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			int nextdis = v[now.to][i].dist;
			int nextnode = v[now.to][i].to;

			if (dis[nextnode] <= dis[now.to] + nextdis)continue;
			dis[nextnode] = dis[now.to] + nextdis;
			pq.push({ nextnode, dis[nextnode] });
		}
	}

	cout << "#" << test_case+1 << " " << dis[n] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for(test_case = 0; test_case<t;test_case++){
		cin >> n >> e;
		v = vector<vector<edge>>(n + 1, vector<edge>());
		for (int i = 0; i < e; i++) {
			int from, to, dist;
			cin >> from >> to >> dist;
			v[from].push_back({ to, dist });
		}

		dijkstra();

	}

}