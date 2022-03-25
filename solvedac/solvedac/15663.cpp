#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int arr[8];
int path[8];
int used[8];

vector < vector<int>> v;
int n, m;

void dfs(int lv) {
	if (lv == m) {
		vector<int> t;
		for (int i = 0; i < m; i++) {
			t.push_back(path[i]);
		}
		v.push_back(t);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			path[lv] = arr[i];
			used[i] = 1;
			dfs(lv + 1);
			path[lv] = 0;
			used[i] = 0;
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

	dfs(0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
;		}
		cout << "\n";
	}

}