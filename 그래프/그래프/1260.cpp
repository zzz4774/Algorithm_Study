#include<iostream>
#include<queue>
using namespace std;
int map[1001][1001];
int dfsused[1001];
int bfsused[10001];
queue <int> q;
int n, m, v;


void dfs(int now) {
	cout << now << " ";

	for (int i = 1; i <= n; i++) {
		if (map[now][i] == 1 && dfsused[i] == 0) {
			dfsused[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int now) {
	q.push(now);

	while (!q.empty()) {
		int value;
		value = q.front();
		q.pop();
		cout << value << " ";

		for (int i = 1; i <= n; i++) {
			if (map[value][i] == 1 && bfsused[i] == 0) {
				bfsused[i] = 1;
				q.push(i);
			}
		}
	}

	cout << endl;

}


int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}

	dfsused[v] = 1;
	bfsused[v] = 1;
	dfs(v);
	cout << endl;
	bfs(v);

	return 0;

}