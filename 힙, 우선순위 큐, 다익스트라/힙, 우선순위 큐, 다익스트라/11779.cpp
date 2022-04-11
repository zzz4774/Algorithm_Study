#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int n, m;
struct edge {
	int to;
	ll dist;
};
vector<vector<edge>> v;
int start, last;
vector <ll> dis;
vector<int> visit;
priority_queue<edge> pq;
vector<int>path;
int route[1001];

bool operator<(edge a, edge b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.to < b.to)return 0;
	if (a.to > b.to)return 1;
	return 0;
}

void dijkstra() {
	dis = vector<ll>(n + 1, 987654321);
	visit = vector<int>(n + 1);

	dis[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		

		if (visit[now.to])continue;
		visit[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			int nextnode = v[now.to][i].to;
			ll d = v[now.to][i].dist;

			if (dis[nextnode] <= dis[now.to] + d)continue;
			dis[nextnode] = dis[now.to] + d;
			route[nextnode] = now.to;
			pq.push({ nextnode, dis[nextnode] });
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
		int from, to;
		ll dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}
	cin >> start >> last;
	dijkstra();

	cout << dis[last] << endl;
	int tmp = last;
	while (tmp) {
		path.push_back(tmp);
		tmp = route[tmp];
	}
	cout << path.size() << endl;

	for (int i = path.size()-1; i >=0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
}