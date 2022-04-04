#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int dp[1001][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	int n;
	cin >> n;

	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < 10; i++) {
			dp[k][i] += dp[k - 1][0];
		}

		for (int i = 1; i < 10; i++) {
			dp[k][i] += dp[k - 1][1];
		}

		for (int i = 2; i < 10; i++) {
			dp[k][i] += dp[k - 1][2];
		}

		for (int i = 3; i < 10; i++) {
			dp[k][i] += dp[k - 1][3];
		}

		for (int i = 4; i < 10; i++) {
			dp[k][i] += dp[k - 1][4];
		}

		for (int i = 5; i < 10; i++) {
			dp[k][i] += dp[k - 1][5];
		}

		for (int i = 6; i < 10; i++) {
			dp[k][i] += dp[k - 1][6];
		}
		for (int i = 7; i < 10; i++) {
			dp[k][i] += dp[k - 1][7];
		}

		for (int i = 8; i < 10; i++) {
			dp[k][i] += dp[k - 1][8];
		}

		for (int i = 9; i < 10; i++) {
			dp[k][i] += dp[k - 1][9];
		}

		for (int i = 0; i < 10; i++) {
			dp[k][i] %= 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}

	sum %= 10007;
	cout << sum << endl;

}