#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
char map[100][100];
int used[100][100];
struct node {
	int y;
	int x;
};

int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};

queue<node> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	q.push({ 0,0 });
	used[0][0] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];

			if (dy >= 0 && dy < n && dx >= 0 && dx < m && map[dy][dx] == '1'&&used[dy][dx]==0) {
				used[dy][dx] = used[now.y][now.x] + 1;
				q.push({ dy,dx });
			}
		}

	}
	cout << used[n - 1][m - 1] << endl;
}