#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char arr[15];
int l, c;
char path[15];

void dfs(int lv, int go) {
	if (lv == l) {
		int ant = 0;
		int bnt = 0;
		for (int i = 0; i < l; i++) {
			if (path[i] == 'a' || path[i] == 'e' || path[i] == 'i' || path[i] == 'o' || path[i] == 'u')ant++;
		}
		bnt = l - ant;
		if (ant >= 1 && bnt >= 2) {
			cout << path << "\n";
		}
		return;
	}

	for (int i = go; i < c; i++) {
		path[lv] = arr[i];
		dfs(lv + 1, i + 1);
		path[lv] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	dfs(0,0);

}