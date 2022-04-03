#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll dp[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	int k;
	cin >> k;
	for (int i = 2; i <= k; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[k]<<endl;

}