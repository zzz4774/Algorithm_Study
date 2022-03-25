#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct node {
	int y;
	int x;
};

struct food {
	int y;
	int x;
	int dist;
};
int n;
int used[21][21];
int map[21][21];
int timeval = 0;
int sharksize = 2;
int cnt = 0;
queue<node> q;
vector<food> v;

int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};

int babyy, babyx;
int min_dis = 1000000;

bool compare(food a, food b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

void bfs(int babyy, int babyx) {
	memset(used, 0, sizeof(used));
	q.push({ babyy,babyx });
	v.clear();
	int eat = min_dis;

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = now.x + dir[i][1];
			int dy = now.y + dir[i][0];


			if (dy >= 0 && dy < n && dx >= 0 && dx < n && map[dy][dx] <= sharksize && used[dy][dx] == 0) {
				used[dy][dx] = used[now.y][now.x] + 1;
				q.push({ dy,dx });
				if (map[dy][dx] < sharksize && map[dy][dx] > 0) {
					if (eat >= used[dy][dx]) {
						eat = used[dy][dx];
						v.push_back({ dy,dx,eat });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 9) {
				map[i][j] = 0;
				babyy = i;
				babyx = j;
				break;
			}
		}
	}


	while (1) {
		bfs(babyy, babyx);
		if (v.empty())break;
		else {
			sort(v.begin(), v.end(), compare);
			timeval += v[0].dist;
			map[v[0].y][v[0].x] = 0;
			babyy = v[0].y;
			babyx = v[0].x;
			cnt++;
			if (cnt == sharksize) {
				sharksize++;
				cnt = 0;
			}
		}

	}
	cout << timeval << "\n";
	return 0;

}