#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int map[9][9];
struct node {
	int y;
	int x;
};
vector<node> v;
int m;

void dfs(int lv) {
	if (lv == v.size()) {
		if (!m) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << map[i][j] << " ";
				}
				cout << '\n';
			}
			m = 1;
		}
		return;
	}

	int dy = v[lv].y;
	int dx = v[lv].x;

	for (int i = 1; i <= 9; i++) {
		map[dy][dx] = i;

		int flag = 1;
		for (int k = 0; k < 9; k++) {
			if (map[dy][k] == i && k != dx) {
				flag = 0;
				break;
			}
		}
		if (!flag) continue;

		for (int k = 0; k < 9; k++) {
			if (map[k][dx] == i && k != dy) {
				flag = 0;
				break;
			}
		}
		if (!flag) continue;

		for (int v = 0; v < 9; v += 3) {
			for (int w = 0; w < 9; w += 3) {

				if ((dy < v || dy >= v + 3) || (dx < w || dx >= w + 3))continue;

				for (int ny = v; ny < v + 3; ny++) {
					for (int nx = w; nx < w + 3; nx++) {
						if (map[ny][nx] == i && (ny != dy || nx != dx)) {
							flag = 0;
							break;
						}
						
					}
				}
			}
		}
		if (!flag)continue;

		dfs(lv + 1);
		
	}
	map[dy][dx] = 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)v.push_back({ i,j });
		}
	}

	dfs(0);


}