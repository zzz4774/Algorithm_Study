#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[8];
int n, m;
int path[8];
void dfs(int lv,int s) {
	if (lv == m) {
		for (int i = 0; i < m; i ++ ) {
			cout << path[i]<<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = s; i < n; i++) {
		path[lv] = arr[i];
		dfs(lv + 1, i);
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
	dfs(0,0);

}