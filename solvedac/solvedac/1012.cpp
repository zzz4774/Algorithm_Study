#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int map[50][50];
int dir[4][2] = {
	1,0,
	-1,0,
	0,-1,
	0,1
};

struct lay {
	int y;
	int x;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		cin >> m >> n >> k;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					queue <lay> q;
					q.push({ i,j });
					map[i][j] = 0;
					cnt++;

					while (!q.empty()) {
						lay now = q.front();
						q.pop();

						for (int a = 0; a < 4; a++) {
							int dy = now.y + dir[a][0];
							int dx = now.x + dir[a][1];

							if (dy >= 0 && dy < n && dx >= 0 && dx < m && map[dy][dx] == 1) {
								map[dy][dx] = 0;
								q.push({ dy,dx });
							}
						}
					}
				
				}
			}
		}


		cout << cnt << "\n";
	}


}