#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[9];
int path[7];
int flag = 1;
int res[7];
void dfs(int lv, int go) {
	if (lv == 7) {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += path[i];
		}
		if (sum == 100) {
			sort(path, path + 7);
			for (int i = 0; i < 7; i++) {
				res[i] = path[i];
			}
		}
		return;
	}

	for (int i = go; i < 9; i++) {
		path[lv] = arr[i];
		dfs(lv + 1, i + 1);
		path[lv] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	
	for (int i = 0; i < 7; i++) {
		cout << res[i] << endl;
	}

}