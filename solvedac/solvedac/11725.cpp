#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n;
int dat[1000001];
int used[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> n;
	vector<vector<int>> v(n+1);
	for (int i = 0; i <= n-2; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	queue<int> q;

	q.push(1);
	used[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			if (used[v[now][i]] == 0) {
				used[v[now][i]] = 1;
				dat[v[now][i]] = now;
				q.push(v[now][i]);
			}
		}
	}


	for (int i = 2; i <= n; i++) {
		cout << dat[i] << "\n";
	}

}