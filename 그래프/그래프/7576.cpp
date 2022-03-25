#include<iostream>
#include<queue>
using namespace std;
int n;
int m;
int map[300][300];
int arr[300][300];
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};
struct lay {
	int y;
	int x;
};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int year = 0;
	while (1) {
		year++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0)arr[i][j] = 1;
				else arr[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] <= 0)continue;
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[k][0];
					int dx = j + dir[k][1];
					if (dy >= 0 && dy < n && dx >= 0 && dx < m && arr[dy][dx] == 0) {
						if (map[i][j] > 0) {
							map[i][j]--;
						}
					}
				}
			}
		}

		queue<lay> q;
		int indexy = 0;
		int indexx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0)arr[i][j] = 1;
				else arr[i][j] = 0;


				if (map[i][j] != 0) {
					indexy = i;
					indexx = j;
				}
			}
		}


		q.push({ indexy,indexx });
		arr[indexy][indexx] = 0;

		while (!q.empty()) {
			lay now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int dy = now.y + dir[i][0];
				int dx = now.x + dir[i][1];
				if (dy >= 0 && dy < n && dx >= 0 && dx < m && arr[dy][dx] == 1) {
					arr[dy][dx] = 0;
					q.push({ dy,dx });
				}
			}
		}

		int flag = 1;
		int zeroflag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					flag = 0;
				}
				if (map[i][j] != 0) {
					zeroflag = 1;
				}
			}
		}
		

	

		if (!zeroflag) {
			cout << 0;
			break;
		}
		else if (!flag) {
			cout << year;
			break;
		}
	}

}