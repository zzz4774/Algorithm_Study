#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char map[500][500];
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	int flag = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[k][0];
					int dx = j + dir[k][1];

					if (dy >= 0 && dy < r && dx >= 0 && dx < c && map[dy][dx] == '.') {
						map[dy][dx] = 'D';
					}
					else if (dy >= 0 && dy < r && dx >= 0 && dx < c && map[dy][dx] == 'S') {
						flag = 0;
						break;
					}
				}
			}
		}
	}

	if (!flag)cout << 0 << endl;
	else {
		cout << 1 << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
	}
}