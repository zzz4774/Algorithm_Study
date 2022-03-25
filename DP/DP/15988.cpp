#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll dp[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
		}

		cout << dp[n] << "\n";
	}

}