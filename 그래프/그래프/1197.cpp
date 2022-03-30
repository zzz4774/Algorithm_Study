#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

vector<int>parents; //유니온 파인드용 배열
struct edge {
	int from;
	int to;
	ll cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int find(int x) { // 조상찾기
	if (x == parents[x])return x;
	return parents[x] = find(parents[x]);
}

void unionf(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parents[pb] = pa;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e;
	cin >> n >> e;
	parents = vector<int>(n + 1);

	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}
	vector<edge> ed;

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		ed.push_back({ from, to, cost });
	}


	sort(ed.begin(), ed.end(), compare);
	int sum = 0;
	for (int i = 0; i < e; i++) {
		edge now = ed[i];

		if (find(now.from) == find(now.to))continue;
		unionf(now.from, now.to);
		sum += now.cost;
	}

	cout << sum << endl;

}