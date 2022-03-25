#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int map[100][100];
int arr[100][100];
struct node {
	int y;
	int x;
};
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (max < map[i][j])max = map[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < max; i++) {

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (map[a][b] > i)arr[a][b] = 1;
			}
		}

		int cnt = 0;

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (arr[a][b] == 1) {
					queue<node> q;
					q.push({ a,b });
					cnt++;

					while (!q.empty()) {
						node now = q.front();
						q.pop();

						if (arr[now.y][now.x] == 0)continue;
						arr[now.y][now.x] = 0;

						for (int j = 0; j < 4; j++) {
							int dy = now.y + dir[j][0];
							int dx = now.x + dir[j][1];

							if (dy < 0 || dy >= n || dx < 0 || dx >= n)continue;
							q.push({ dy,dx });
						}
					}
				}



			}
		}

		if (res < cnt)res = cnt;
	}

	cout << res << endl;

}