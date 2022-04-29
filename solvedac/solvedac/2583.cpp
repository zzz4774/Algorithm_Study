#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int map[100][100];
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

	int m, n, k;
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				map[j][i] = 1;
			}
		}
	}

	vector<int> v;
	int num = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				queue<node> q;
				num++;
				int cnt = 0;
				q.push({ i,j });

				while (!q.empty()) {
					node now = q.front();
					q.pop();

					if (map[now.y][now.x] == 1)continue;
					map[now.y][now.x] = 1;
					cnt++;

					for (int k = 0; k < 4; k++) {
						int ny = now.y + dir[k][0];
						int nx = now.x + dir[k][1];

						if (map[ny][nx] == 1 || ny < 0 || ny >= m || nx < 0 || nx >= n)continue;
						q.push({ ny,nx });
					}
				}

				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << num << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	

}