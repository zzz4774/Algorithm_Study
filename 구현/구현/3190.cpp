#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct f {
	int p;
	int len;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>>v(n+1);
	vector<int>visited(n + 1);
	for (int i = 0; i < k; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	queue<f> q;
	q.push({ 1,0 });
	int cnt = -1;

	while (!q.empty()) {
		f now = q.front();
		q.pop();
		if (visited[now.p] != 0)continue;
		if (now.len > 2)continue;
		visited[now.p] = 1;
		cnt++;

		for (int i = 0; i < v[now.p].size(); i++) {
			q.push({ v[now.p][i], now.len + 1 });
		}
	}

	cout << cnt << "\n";
}