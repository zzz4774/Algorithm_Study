#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n;
int map[125][125];
vector<vector<int>>v;
struct edge {
	int y;
	int x;
	int dist;
};

int dir[4][2] = {
	-1,0,
	0,-1,
	0,1,
	1,0
};

int dijkstra() {
	v = vector<vector<int>>(n + 1, vector<int>(n + 1, 213456789));
	queue<edge> q;

	q.push({ 0, 0, map[0][0] });
	v[0][0] = map[0][0];

	while (!q.empty()) {
		edge now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];


			if (dy < 0 || dy >= n || dx < 0 || dx >= n)continue;
			if (v[dy][dx] <= v[now.y][now.x] + map[dy][dx])continue;
			v[dy][dx] = v[now.y][now.x] + map[dy][dx];
			q.push({ dy,dx,v[dy][dx] });
		}

	}


	return v[n - 1][n - 1];
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num = 1;
	while (1) {

		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		cout << "Problem " << num << ": " << dijkstra() << "\n";
		num++;
	}
	




}