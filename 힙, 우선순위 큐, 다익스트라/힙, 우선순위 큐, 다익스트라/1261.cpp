#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char map[100][100];
int dp[100][100];
int n, m;
struct node {
	int y;
	int x;
	int dist;
};
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};

bool operator<(node a, node b) {
	if (a.dist < b.dist)return 0;
	if (a.dist > b.dist)return 1;
	if (a.y < b.y)return 0;
	if (a.y > b.y)return 1;
	if (a.x < b.x)return 0;
	if (a.x > b.x)return 1;
	return 0;
}


priority_queue<node> pq;
void dijkstra() {

	memset(dp, 2134567, sizeof(dp));

	pq.push({ 0,0,0 });
	dp[0][0] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];

			if (dx < 0 || dx >= m || dy < 0 || dy >= n)continue;
			if (map[dy][dx] == '1') {
				if (dp[dy][dx] <= now.dist + 1)continue;
				dp[dy][dx] = now.dist + 1;
				pq.push({ dy,dx,dp[dy][dx] });
			}
			else {
				if (dp[dy][dx] <= now.dist)continue;
				dp[dy][dx] = now.dist;
				pq.push({ dy,dx,dp[dy][dx] });
			}
		}


	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	dijkstra();

	cout << dp[n - 1][m - 1] << endl;
}