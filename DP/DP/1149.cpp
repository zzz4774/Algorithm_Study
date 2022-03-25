#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	
	for (int i = 1; i <= n; i++) {
		int cost1, cost2, cost3;
		cin >> cost1 >> cost2 >> cost3;

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost1;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost2;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost3;

	}
	
	cout << min(dp[n][0], min(dp[n][1],dp[n][2])) << endl;
}