#include<iostream>
#include <queue>
using namespace std;
int a, b, n, m;
int map[100001];
queue<int> q;

int main() {
	cin >> a >> b >> n >> m;
	q.push(n);
	map[n] = 1;

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (k == m)break;

		int i = k + 1;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k - 1;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k + a;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k + b;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k - a;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k - b;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k * a;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

		i = k * b;
		if (i >= 0 && i < 100001 && map[i] == 0) {
			map[i] = map[k] + 1;
			q.push(i);
		}

	}
	cout << map[m] - 1;

}