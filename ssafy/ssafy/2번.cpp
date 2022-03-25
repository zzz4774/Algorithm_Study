#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int map[11][11];
struct node {
	int y;
	int x;
};
vector<node> go;
vector<int>used;
int n, nn;
int minx = 213456567;

void dfs(int lv, int ny, int nx, int sum) {
	if (lv == nn) {
		if (minx > sum)minx = sum;
		return;
	}

	for (int i = 1; i <= nn; i++) {
		if (used[i] == 0 && i <= nn / 2) {
			used[i] = 1;
			used[i + nn / 2] = 0;
			int col = sum + abs(go[i].y - ny) + abs(go[i].x - nx);
			dfs(lv + 1, go[i].y, go[i].x, col);
			used[i] = 0;
			used[i + nn / 2] = 1;

		}
		else if (used[i] == 0 && i > nn / 2) {
			used[i] = 1;
			int col = sum + abs(go[i].y - ny) + abs(go[i].x - nx);
			dfs(lv + 1, go[i].y, go[i].x, col);
			used[i] = 0;
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0)nn++;
			}
		}
		used = vector<int>(nn + 1);
		go = vector<node>(nn + 1);
		if (nn == 8) {
			used = { 1,0,0,0,0,1,1,1,1 };
		}
		else if (nn == 6) {
			used = { 1,0,0,0,1,1,1 };
		}
		else if (nn == 4) {
			used = { 1,0,0,1,1 };
		}
		else if (nn == 2) {
			used = { 1,0,1 };
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > 0) {
					go[map[i][j]].y = i;
					go[map[i][j]].x = j;
				}
				else if (map[i][j] < 0) {
					go[(map[i][j]) * (-1) + nn / 2].y = i;
					go[(map[i][j]) * (-1) + nn / 2].x = j;
				}
			}
		}

		dfs(0, 1, 1, 0);



		nn = 0;
		cout << "#" << tc << " " << minx << '\n';
		minx = 213456567;
	}
}