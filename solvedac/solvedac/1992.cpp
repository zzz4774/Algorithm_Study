#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char map[64][64];

void cut(int y, int x, int size) {

	int flag = 1;
	if (map[y][x] == '0') {
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (map[i][j] != '0') {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			cout << 0;
			return;
		}
	}
	else if (map[y][x] == '1') {
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (map[i][j] != '1') {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			cout << 1;
			return;
		}
	}
	cout << "(";
	cut(y, x, size / 2);
	cut(y, x + size / 2, size / 2);
	cut(y + size / 2, x, size / 2);
	cut(y + size / 2, x + size / 2, size / 2);
	cout << ")";
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cut(0, 0, n);


}