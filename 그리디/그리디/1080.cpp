#include<iostream>
using namespace std;
char map[50][50];
char result[50][50];
int y, x, cnt;


int main() {
	cin >> y >> x;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> result[i][j];
		}
	}

	for (int i = 0; i < y - 2; i++) {
		for (int j = 0; j < x - 2; j++) {
			if (map[i][j] != result[i][j]) {
				for (int a = i; a <= i + 2; a++) {
					for (int b = j; b <= j + 2; b++) {
						if (map[a][b] == '1')map[a][b] = '0';
						else map[a][b] = '1';
					}
				}
				cnt++;
			}
		}
	}
	
	int flag = 1;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] != result[i][j]) {
				flag = 0;
				break;
			}
		}
	}

	if (flag) cout << cnt;
	else cout << -1;

}