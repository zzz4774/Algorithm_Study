#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int map[1005][1005];
int cnt;
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}
	for (int i = 1; i <= n; i++) {
		map[i][i] = 1;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				cnt++;
				map[i][j] = 0;
				map[j][i] = 0;
				q.push(j);

				while (!q.empty()) {
					int now = q.front();
					q.pop();

					for (int k = 1; k <= n; k++) {
						if (map[now][k] == 1) {
							map[now][k] = 0;
							map[k][now] = 0;
							q.push(k);
						}
					}
				}
			}
		}
	}

	cout << cnt << endl;

}