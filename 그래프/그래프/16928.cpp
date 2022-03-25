#include<iostream>
#include<queue>
using namespace std;
int n;
int m;
int map[101];
int go[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int from, to;
		cin >> from >> to;
		go[from] = to;
	}

	queue<int> q;
	q.push(1);
	map[1] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (k == 100)break;

		for (int i = k+1; i <= k+6; i++) {
			if (map[i] == 0) {
				if (go[i] == 0) {
					map[i] = map[k] + 1;
					q.push(i);
				}
				else {
					int goindex = go[i];
					if (map[goindex] == 0) {
						map[goindex] = map[k] + 1;
						q.push(goindex);
					}
				}
			}
		}
	}

	cout << map[100] - 1;

}