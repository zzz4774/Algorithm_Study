#include<iostream>
using namespace std;
int w, h;
int map[50][50];
int cnt;

int dir[8][2] = {
	1,0,
	1,1,
	1,-1,
	-1,0,
	-1,1,
	-1,-1,
	0,1,
	0,-1
};

int where[8][2];

void dfs(int y, int x) {

	for (int i = 0; i < 8; i++) {
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if (dy >= 0 && dy < h && dx >= 0 && dx < w) {
			if (map[dy][dx] == 1) {
				map[dy][dx] = 0;
				dfs(dy, dx);
			}
		}
	}
}


int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
					dfs(i, j);
					cnt++;
				}
			}
		}

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
}