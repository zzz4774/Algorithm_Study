#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll dp[101][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 < 0)continue;
			dp[i][j] += dp[i - 1][j - 1];
		}

		for (int j = 0; j <= 9; j++) {
			if ( j + 1 > 9)continue;
			dp[i][j] += dp[i - 1][j + 1];
		}

		for (int j = 0; j <= 9; j++) {
			dp[i][j] %= 1000000000;
		}

	}

	ll sum = 0;

	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum << endl;
}