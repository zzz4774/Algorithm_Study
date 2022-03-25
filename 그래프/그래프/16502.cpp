#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
float map[4][4];
float per[10][4];

void dfs(int lv) {
	if (lv == n) {
		cout << fixed;
		cout.precision(2);
		for (int i = 0; i < 4; i++) {
			cout << per[lv][i] << "\n";
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j] != 0) {
				per[lv+1][j] += per[lv][i] * map[i][j];
			}
		}
	}
	dfs(lv + 1);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char from, to;
		float dist;
		cin >> from >> to >> dist;
		map[int(from - 'A')][int(to - 'A')] = dist;
	}

	for (int i = 0; i < 4; i++) {
		per[0][i] = 25;
	}
	dfs(0);

}