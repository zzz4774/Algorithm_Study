#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int map[101][101];
int kev[101];
int used[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}

	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		used[i] = 1;

		while (!q.empty()) {
			int now = q.front();
			q.pop();


			for (int a = 1; a <= n; a++) {
				if (map[now][a] == 1 && used[a] == 0) {
					used[a] = used[now] + 1;
					q.push(a);
				}
			}
		}


		for (int a = 1; a <= n; a++) {
			kev[i] += used[a] - 1;
			used[a] = 0;
		}

	}


	int min = 100000;
	for (int i = 1; i <= n; i++) {
		if (min > kev[i])min = kev[i];
	}

	for (int i = 1; i <= n; i++) {
		if (min == kev[i]) {
			cout << i << "\n";
			break;
		}
	}
}