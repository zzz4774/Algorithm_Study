#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int map[100][100];
int arr[100][100];
int n, m;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			arr[i][j] = map[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					flag = 0;
					break;
				}
			}
		}

		if (flag)break;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = map[i][j];
			}
		}






		queue<node> q;
		q.push({ 0, 0 });

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			if (arr[now.y][now.x] != 0)continue;
			arr[now.y][now.x] = 2;

			for (int i = 0; i < 4; i++) {
				int dy = now.y + dir[i][0];
				int dx = now.x + dir[i][1];

				if (dy < 0 || dy >= n || dx < 0 || dx >= m)continue;
				if (arr[dy][dx] != 0)continue;
				q.push({ dy,dx });
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					int num = 0;
					for (int k = 0; k < 4; k++) {
						int dy = i + dir[k][0];
						int dx = j + dir[k][1];
						if (arr[dy][dx] == 2)num++;
					}

					if (num > 1)arr[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1)map[i][j] = 1;
				else map[i][j] = 0;
			}
		}

		cnt++;
	}

	cout << cnt << endl;

}