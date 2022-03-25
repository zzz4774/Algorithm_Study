#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
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
int map[8][8];
int arr[8][8];
vector<node>v;
node path[3];
int n, m;
int maxn;
int cnt;
void bfs() {
	for (int i = 0; i < 3; i++) {
		arr[path[i].y][path[i].x] = 1;
	}

	queue<node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2)q.push({ i, j });
		}
	}

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];

			if (dy >= 0 && dy < n && dx >= 0 && dx < m && arr[dy][dx] == 0) {
				arr[dy][dx] = 2;
				q.push({ dy,dx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)cnt++;
			arr[i][j] = map[i][j];
		}
	}
}



void dfs(int lv, int go) {
	if (lv == 3) {
		bfs();
		if (maxn < cnt)maxn = cnt;
		cnt = 0;
		return;
	}

	for (int i = go; i < v.size(); i++) {
		path[lv] = v[i];
		dfs(lv + 1, i + 1);
		path[lv] = { 0,0 };
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			arr[i][j] = map[i][j];
			if (map[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);
	cout << maxn << endl;

}