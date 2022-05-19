#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
typedef long long ll;
int arr[100][100];
int map[100][100];

int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};

struct node {
	int y;
	int x;
};

struct vec {
	int y;
	int x;
	int lv;
};

int minn = 10001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && map[i][j] == 0) {
				queue<node> q;
				q.push({ i,j });
				vector<vector<int>> visited(n, vector<int>(n));

				while (!q.empty()) {
					node now = q.front();
					q.pop();

					
					if (visited[now.y][now.x] == 1)continue;
					visited[now.y][now.x] = 1;

					map[now.y][now.x] = cnt;

					for (int i = 0; i < 4; i++) {
						int dy = now.y + dir[i][0];
						int dx = now.x + dir[i][1];
						if (dy < 0 || dy >= n || dx < 0 || dx >= n)continue;
						if (arr[dy][dx] == 1) {
							q.push({ dy,dx });
						}
					}
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				int val = map[i][j];
				queue<vec> q;
				q.push({ i,j,0 });
				vector<vector<int>> visited(n, vector<int>(n));

				while (!q.empty()) {
					vec now = q.front();
					q.pop();


					if (visited[now.y][now.x] == 1)continue;
					visited[now.y][now.x] = 1;
					
					if (map[now.y][now.x] != 0 && map[now.y][now.x] != val) {
						if (minn > now.lv)minn = now.lv;
						break;
					}

					

					for (int i = 0; i < 4; i++) {
						int dy = now.y + dir[i][0];
						int dx = now.x + dir[i][1];

						if (dy < 0 || dy >= n || dx < 0 || dx >= n)continue;
						else if (now.lv == minn)continue;
						q.push({ dy,dx, now.lv+1 });
						
					}
				}
			}
		}
	}
	cout << minn - 1 << endl;
}