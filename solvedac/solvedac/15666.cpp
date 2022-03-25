#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int arr[8];
int path[8];
int vec[8];
int n, m;
vector<vector<int>> v;
void dfs(int lv, int a) {
	if (lv == m) {
		vector<int> tmp;
		for (int i = 0; i < m; i++) {
			tmp.push_back(path[i]);
		}
		sort(tmp.begin(), tmp.end());
		v.push_back(tmp);
		return;

	}
	for (int i = a; i < n; i++) {
		path[lv] = arr[i];
		dfs(lv + 1, i);
		path[lv] = 0;
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

	dfs(0, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}


}