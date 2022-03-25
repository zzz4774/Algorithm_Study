#include<iostream>
using namespace std;
int map[101][101];
int cnt;
int used[1000];
int com, link;

void dfs(int now) {
	for (int i = 0; i <= com; i++) {
		if (map[now][i] == 1 && used[i] == 0) {
			used[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	cin >> com >> link;
	for (int i = 0; i < link; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}

	used[1] = 1;
	dfs(1);
	cout << cnt;
}