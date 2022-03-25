#include<iostream>
#include <queue>
using namespace std;
int map[3][3];
int n;
int flag;

void dfs(int y, int x) {
	if (map[y][x] == -1) {
		flag = 1;
		return;
	}

	int num = map[y][x];
	int dy = y + num;
	int dx = x + num;

	if (num != 0) {
		if (dy < n) {
			dfs(dy, x);
		}
		if (dx < n) {
			dfs(y, dx);
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0);
	if (flag)cout << "HaruHaru";
	else cout << "Hing";


	return 0;
}