#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int map[500][500];
int dp[500][500];
int n;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + map[i][0];
		dp[i][i] = dp[i - 1][i - 1] + map[i][i];
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + map[i][j], dp[i - 1][j] + map[i][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[n - 1][i])max = dp[n - 1][i];
	}

	cout << max << endl;
}