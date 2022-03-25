#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[8];
int n, m;
int path[8];
int used[8];
int res[8];

void dfs(int lv) {
	if (lv == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i]<<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			path[lv] = arr[i];
			dfs(lv + 1);
			used[i] = 0;
			path[lv] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0);

}