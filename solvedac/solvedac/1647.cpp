#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int> parent;
struct edge {
	int from;
	int to;
	int dist;
};

bool compare(edge a, edge b) {
	return a.dist < b.dist;
}

int find(int now) {
	if (parent[now] == now)return now;
	return parent[now] = find(parent[now]);
}

void unionf(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	parent[fb] = fa;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<edge> v;
	for (int i = 0; i < m; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v.push_back({ from, to, dist });
	}

	sort(v.begin(), v.end(), compare);
	int sum = 0;
	int lastval = 0;
	for (int i = 0; i < m; i++) {
		edge now = v[i];

		if (find(now.from) == find(now.to))continue;
		unionf(now.from, now.to);
		sum += now.dist;
		lastval = now.dist;
	}

	cout << sum - lastval << endl;


}