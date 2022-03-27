#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct edge {
	int to;
	int dist;
};

int sum;
int space;
int n;
int visited[10002];
vector<vector<edge>> v(10002, vector<edge>());

void dfs(int start, int weight) {
	if (visited[start])return;
	visited[start] = 1;

	if (sum < weight) {
		sum = weight;
		space = start;
	}

	for (long unsigned int i = 0; i < v[start].size(); i++) {
		dfs(v[start][i].to, weight + v[start][i].dist);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int to, from, dist;
		cin >> to >> from >> dist;
		v[to].push_back({ from, dist });
		v[from].push_back({ to, dist });
	}
	
	dfs(1, 0);

	sum = 0;
	memset(visited, 0, sizeof(visited));

	dfs(space, 0);
	cout << sum << endl;

}