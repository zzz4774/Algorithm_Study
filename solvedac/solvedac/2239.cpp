#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

bool finish = false;
int arr[9][9];

void back_track(int num) {
	if (finish) return;
	if (num == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j];
			cout << '\n';
		}
		finish = true;
		return;
	}
	int y = num / 9;
	int x = num % 9;
	if (arr[y][x] != 0) back_track(num + 1);
	else {
		for (int i = 1; i < 10; i++) {
			bool flag = true;
			for (int j = 0; j < 9; j++) {
				if (arr[y][j] == i || arr[j][x] == i) {
					flag = false;
					break;
				}
			}
			if (!flag) continue;
			int ny = (y / 3) * 3;
			int nx = (x / 3) * 3;
			for (int j = ny; j < ny + 3; j++) {
				for (int k = nx; k < nx + 3; k++) {
					if (arr[j][k] == i) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) {
				arr[y][x] = i;
				back_track(num + 1);
				arr[y][x] = 0;
			}
		}
	}
}

int main() {
	string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++)
			arr[i][j] = str[j] - '0';
	}
	back_track(0);
}