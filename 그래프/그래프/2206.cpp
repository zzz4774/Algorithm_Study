#include<iostream>
#include<queue>
using namespace std;
int n, m;
char map[1001][1001];
int used[1001][1001][2];
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
struct lay {
	int y;
	int x;
	int cnt;
};
int maxlen;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		map[i][0] = '0';
	}
	for (int i = 0; i <= m; i++) {
		map[0][i] = '0';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	
	queue<lay> q;
	q.push({ 1, 1, 1 });
	used[1][1][1] = 1;

	while (!q.empty()) {
		lay now = q.front();
		q.pop();
		if (now.y == n && now.x == m) {
			cout << used[now.y][now.x][now.cnt];
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int dy = now.y + dir[k][0];
			int dx = now.x + dir[k][1];
			

			if (dy >= 1 && dy <= n && dx >= 1 && dx <= m && map[dy][dx] == '0' && used[dy][dx][now.cnt]==0) {
				q.push({ dy,dx,now.cnt });
				used[dy][dx][now.cnt] = used[now.y][now.x][now.cnt] + 1;
			}

			if (dy >= 1 && dy <= n && dx >= 1 && dx <= m && map[dy][dx] == '1' && now.cnt == 1) {
				q.push({ dy,dx,0 });
				used[dy][dx][0] = used[now.y][now.x][1] + 1;

			}
		}
	}


	cout << -1;
	return 0;
}