#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
char map[2200][2200];

void star(int y, int x, int now) {
	if (now == 3) {
		for (int i = y; i < y + 3; i++) {
			for (int j = x; j < x + 3; j++) {
				map[i][j] = '*';
			}
		}
		map[y + 1][x + 1] = ' ';
	}
	else {
		star(y, x, now / 3);
		star(y + (now / 3), x, now / 3);
		star(y + 2 * (now / 3), x, now / 3);
		star(y, x + (now / 3), now / 3);
		star(y + 2 * (now / 3), x + (now / 3), now / 3);
		star(y, x + 2 * (now / 3), now / 3);
		star(y + (now / 3), x + 2 * (now / 3), now / 3);
		star(y + 2 * (now / 3), x + 2 * (now / 3), now / 3);

		for (int i = y + (now / 3); i < y + 2 * (now / 3); i++) {
			for (int j = x + (now / 3); j < x + 2 * (now / 3); j++) {
				map[i][j] = ' ';
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	star(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}