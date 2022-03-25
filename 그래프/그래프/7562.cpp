#include<iostream>
#include <queue>
using namespace std;
int test_case;
int map[300][300];
int used[300][300];
int startx;
int starty;
int lastx;
int lasty;
int len;

struct lay {
	int y;
	int x;
};

int dir[8][2] = {
	-2,1,
	-1,2,
	1,2,
	2,1,
	1,-2,
	2,-1,
	-1,-2,
	-2,-1
};

int main() {
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> len;
		cin >> starty >> startx;
		cin >> lasty >> lastx;
		queue<lay> q;

		q.push({ starty,startx });
		used[starty][startx] = 1;

		while (!q.empty()) {
			lay k = q.front();
			q.pop();
			if (k.y == lasty && k.x == lastx)break;

			for (int i = 0; i < 8; i++) {
				int dy = k.y + dir[i][0];
				int dx = k.x + dir[i][1];

				if (dy >= 0 && dy < len && dx >= 0 && dx < len) {
					if (used[dy][dx] == 0) {
						used[dy][dx] = used[k.y][k.x] + 1;
						q.push({ dy, dx });
					}
				}
			}
		}



		cout << used[lasty][lastx] - 1 << endl;

		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				map[i][j] = 0;
				used[i][j] = 0;
			}
		}




	}
	return 0;
}