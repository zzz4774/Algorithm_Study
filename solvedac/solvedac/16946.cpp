#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int y;
	int x;
};
char map[1001][1001];
int res[1001][1001];
int group[1001][1001];
int visited[1001][1001];
int area[1000000];
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
int n, m;
int num = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '0' && visited[i][j] == 0) {
				
				queue<node>q;
				q.push({ i,j });
				visited[i][j] = 1;
				int cnt = 0;

				while (!q.empty()) {
					node now = q.front();
					q.pop();
					cnt++;
					group[now.y][now.x] = num;

					for (int i = 0; i < 4; i++) {
						int dy = now.y + dir[i][0];
						int dx = now.x + dir[i][1];

						if (dy < 0 || dy >= n || dx < 0 || dx >= m || visited[dy][dx] != 0 || map[dy][dx] == '1')continue;
						q.push({ dy,dx });
						visited[dy][dx] = 1;
					}
				}
				area[num] = cnt;
				num++;
			}
			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				int sum = 1;
				vector<int> v;
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[k][0];
					int dx = j + dir[k][1];
					int flag = 0;

					if (dy < 0 || dy >= n || dx < 0 || dx >= m || map[dy][dx] == '1')continue;
					for (int i = 0; i < v.size(); i++) {
						if (v[i] == group[dy][dx]) {
							flag = 1;
							break;
						}
					}
					if (!flag) {
						v.push_back(group[dy][dx]);
						sum += area[group[dy][dx]];
					}
					
				}
				res[i][j] = sum;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (res[i][j] == 0)cout << 0;
			else cout << res[i][j] % 10;
		}
		cout << "\n";
	}
}