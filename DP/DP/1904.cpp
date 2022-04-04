#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int dp[1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n] <<endl;

}