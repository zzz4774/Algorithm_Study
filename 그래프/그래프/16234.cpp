#include<iostream>
#include<queue>
using namespace std;
int map[50][50];
int used[50][50];
int n;
int low;
int high;
int sum[10000];
int cnt[10000];
int arr[50][50];
struct lay {
	int y;
	int x;
};
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
int mastercnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> low >> high;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int flag = 0;
	while (1) {

		queue<lay> q;
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (used[i][j] == 0) {
					q.push({ i,j });
					num++;
					used[i][j] = num;
					sum[num] += map[i][j];
					cnt[num]++;

					while (!q.empty()) {
						lay k = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							int dy = k.y + dir[i][0];
							int dx = k.x + dir[i][1];

							if (dy >= 0 && dy < n && dx >= 0 && dx < n && used[dy][dx] == 0) {
								if (abs(map[dy][dx] - map[k.y][k.x]) >= low && abs(map[dy][dx] - map[k.y][k.x]) <= high) {
									used[dy][dx] = num;
									sum[num] += map[dy][dx];
									cnt[num]++;
									q.push({ dy, dx });
								}
							}
						}
					}

				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sum[used[i][j]] / cnt[used[i][j]];
			}
		}
	
		



		int flag = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != map[i][j]) {
					flag = 0;
					break;
				}
			}
		}
		if (flag)break;

		for (int i=0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				used[i][j] = 0;
			}
		}
		for (int i = 0; i <= num; i++) {
			cnt[i] = 0;
			sum[i] = 0;
		}

		mastercnt++;
	}
	cout << mastercnt;

}