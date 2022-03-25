#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char map[50][50];
int v[50][50];
int n;

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

void dijkstra() {
	queue<node> q;
	memset(v, 4567890, sizeof(v));
	q.push({ 0, 0 });
	v[0][0] = 0;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];

			if (dy<0 || dy>=n || dx<0 || dx>=n)continue;
			if (map[dy][dx] == '0') {
				if (v[dy][dx] <= v[now.y][now.x] + 1)continue;
				v[dy][dx] = v[now.y][now.x] + 1;
				q.push({ dy,dx });
			}
			else {
				if (v[dy][dx] <= v[now.y][now.x])continue;
				v[dy][dx] = v[now.y][now.x];
				q.push({ dy,dx });
			}
		}
	}
	
	cout << v[n - 1][n - 1] << endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0;i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}



	dijkstra();

}