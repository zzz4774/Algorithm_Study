#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int map[101][101][101];
int dir[6][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
struct node {
	int z;
	int y;
	int x;
	int cnt;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y, z;
	cin >> x >> y >> z;

	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				cin >> map[i][j][k];
			}
		}
	}
	queue<node> q;
	int cnt = 0;
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				if (map[i][j][k] == 1) {
					q.push({ i,j,k,0 });
				}
			}
		}
	}

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.cnt > cnt)cnt = now.cnt;
		for (int m = 0; m < 6; m++) {
			int dz = now.z + dir[m][0];
			int dy = now.y + dir[m][1];
			int dx = now.x + dir[m][2];

			if (dy >= 1 && dy <= y && dx >= 1 && dx <= x && dz >= 1 && dz <= z && map[dz][dy][dx] == 0) {
				map[dz][dy][dx] = map[now.z][now.y][now.x] + 1;
				q.push({ dz,dy,dx,now.cnt + 1 });
			}
		}
	}


	int flag = 1;
	for (int i = 1; i <=z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				if (map[i][j][k] == 0) {
					flag = 0;
					break;
				}
			}
		}
	}
	if (!flag)cout << -1 << "\n";
	else {
		cout << cnt << "\n";
	}

}