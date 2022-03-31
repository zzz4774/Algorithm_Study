#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int map[501][501];
ll visit[501][501];
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
ll cnt = 0;
int n, m;

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) return 1;
	if (visit[y][x] != -1)return visit[y][x];

	visit[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];

		if (dy < 0 || dy >= n || dx < 0 || dx >= m)continue;
		if (map[dy][dx] >= map[y][x])continue;
		visit[y][x] = visit[y][x] + dfs(dy, dx);
	}

	return visit[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}

	cnt = dfs(0, 0);

	cout << cnt << endl;
}