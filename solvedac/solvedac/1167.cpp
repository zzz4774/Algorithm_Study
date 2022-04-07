#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int v;
struct node {
	int to;
	int dist;
};

vector<int> visited;
vector<vector<node>>vect;
int sum;
int nextnode = 0;

void dfs(int start, int weight) {
	if (visited[start])return;
	visited[start] = 1;

	if (sum < weight) {
		sum = weight;
		nextnode = start;
	}

	for (int i = 0; i < vect[start].size(); i++) {
		dfs(vect[start][i].to, weight + vect[start][i].dist);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v;
	vect = vector<vector<node>>(v + 1);
	visited = vector<int>(v + 1);
	for (int i = 1; i <= v; i++) {
		int from;
		cin >> from;
		while (1) {
			int to, dist;
			cin >> to;
			if (to == -1)break;
			else {
				cin >> dist;
				vect[from].push_back({ to, dist });
			}
		}
	}

	dfs(1, 0);
	for (int i = 0; i< v + 1; i++) {
		visited[i] = 0;
	}

	dfs(nextnode, 0);
	cout << sum << endl;

}