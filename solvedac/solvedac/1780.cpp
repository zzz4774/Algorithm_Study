#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int map[3000][3000];
int cnt0;
int cnt1;
int cnt2;

void cut(int y, int x, int n) {
	int flag = 0;
	for (int i = y; i <y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (map[y][x] != map[i][j]) {
				flag = 1;
				break;
			}
		}
	}
	if (!flag) {
		if (map[y][x] == 0)cnt0++;
		else if (map[y][x] == 1)cnt1++;
		else cnt2++;
	}
	else {
		cut(y, x, n / 3);
		cut(y, x + n / 3, n / 3);
		cut(y, x + (2 * n) / 3, n / 3);
		cut(y + n / 3, x, n / 3);
		cut(y + n / 3, x + n / 3, n / 3);
		cut(y + n / 3, x + (2 * n) / 3, n / 3);
		cut(y + (2 * n) / 3, x, n / 3);
		cut(y + (2 * n) / 3, x + n / 3, n / 3);
		cut(y + (2 * n) / 3, x + (2 * n) / 3, n / 3);
	}

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
	cout << cnt2 << endl << cnt0 << endl << cnt1 << endl;
}