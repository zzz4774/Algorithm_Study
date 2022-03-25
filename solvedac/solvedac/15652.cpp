#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, m;
int path[8];

void dfs(int lv, int go) {
	if (lv == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = go; i <= n; i++) {
		path[lv] = i;
		dfs(lv + 1, i);
		path[lv] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	dfs(0, 1);

}