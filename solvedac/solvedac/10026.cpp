#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
char map[101][101];
int used[101][101];
int cnt1;
int cnt2;
int n;
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
struct node {
	int y;
	int x;
};

void bfs(int i, int j, char c) {
	queue<node> q;
	q.push({ i,j });
	used[i][j] = 1;
	cnt1++;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dy = now.y + dir[k][0];
			int dx = now.x + dir[k][1];

			if (dy >= 0 && dy < n && dx >= 0 && dx < n && map[dy][dx] == c && used[dy][dx] == 0) {
				q.push({ dy,dx });
				used[dy][dx] = 1;
			}
		}
	}
}

void bfs2(int i, int j, char c, char d) {
	queue<node> q;
	q.push({ i,j });
	used[i][j] = 1;
	cnt2++;
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dy = now.y + dir[k][0];
			int dx = now.x + dir[k][1];

			if (dy >= 0 && dy < n && dx >= 0 && dx < n && (map[dy][dx] == c || map[dy][dx] == d) && used[dy][dx] == 0) {
				q.push({ dy,dx });
				used[dy][dx] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R' && used[i][j] == 0) {
				bfs(i,j, 'R');
			}
			else if (map[i][j] == 'G' && used[i][j] == 0) {
				bfs(i, j, 'G');
			}
			else if (map[i][j] == 'B' && used[i][j] == 0) {
				bfs(i, j, 'B');
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			used[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((map[i][j] == 'R' || map[i][j] == 'G') && used[i][j] == 0) {
				bfs2(i, j, 'R', 'G');
			}
			else if (map[i][j] == 'B' && used[i][j] == 0) {
				bfs2(i, j, 'B', 'B');
			}
		}
	}

	cout << cnt1 << " " << cnt2 << endl;

}