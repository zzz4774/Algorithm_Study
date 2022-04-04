#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll dp[91][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[1][1] = 1;
	dp[2][0] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1] << endl;

}