#include<iostream>
#include<algorithm>
#include<string>
#include<queue>;
using namespace std;
struct node {
	int y;
	int x;
};
char map[30][30];
int dir[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};

int cnt;
int arr[10000];
int used[30][30];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int num = 0;
	queue<node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				map[i][j] = 0;
				q.push({ i,j });
				cnt++;
				arr[num]++;

				while (!q.empty()) {
					node now = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int dy = now.y + dir[k][0];
						int dx = now.x + dir[k][1];

						if (dy >= 0 && dy < n && dx >= 0 && dx < n && map[dy][dx] == '1') {
							arr[num]++;
							map[dy][dx] = '0';
							q.push({ dy,dx });
						}
					}
				}
				num++;
			}
		}
	}

	cout << cnt << "\n";
	sort(arr, arr + num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << "\n";
	}

}