#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
char map[20][20];
int used[20][20];
int dat[100];
int n, m;
int dir[4][2] = {
	1,0,
	-1,0,
	0,-1,
	0,1
};
int res = 0;
void dfs(int y, int x, int lv, int now[100]) {
	if (lv == n * m - 1) {
		res = lv;

	}
	for (int i = 0; i < 4; i++) {
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if (dy < 0 || dy >= n || dx < 0 || dx >= m)continue;
		if (used[dy][dx] == 1)continue;
		

		if (now[map[dy][dx]] == 1) {
			if (res < lv)res = lv;
		}
		else {
			used[dy][dx] = 1;
			now[map[dy][dx]] = 1;
			dfs(dy, dx, lv + 1, now);
			used[dy][dx] = 0;
			now[map[dy][dx]] = 0;
		}
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
		}
	}

	
	
	used[0][0] = 1;
	dat[map[0][0]] = 1;
	dfs(0, 0, 0, dat);


	cout << res + 1 << endl;

}