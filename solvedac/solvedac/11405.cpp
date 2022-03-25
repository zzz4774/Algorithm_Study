#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int map[100][100];
int can[100][100];
int used[100];
int n;

int flag = 0;
void dfs(int start, int end) {
	if (start == end && used[end]==1) {
		flag = 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (map[start][i] == 1 && used[i] == 0) {
			used[i] = 1;
			dfs(i, end);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag = 0;
			dfs(i, j);
			if (flag)can[i][j] = 1;
			for (int k = 0; k < 100; k++) {
				used[k] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << can[i][j] << " ";
		}
		cout << '\n';
	}

}