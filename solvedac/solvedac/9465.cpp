#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[2][100001];
int dp[2][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int maxn = 0;

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 0; i < 2; i++) {
			if (maxn < dp[1][i])maxn = dp[1][i];
			if (maxn < dp[0][i])maxn = dp[0][i];
		}
		
		for (int i = 2; i < n; i++) {
			dp[1][i] = max(dp[0][i - 2] + arr[1][i], dp[0][i - 1] + arr[1][i]);
			dp[0][i] = max(dp[1][i - 2] + arr[0][i], dp[1][i - 1] + arr[0][i]);
			if (maxn < dp[1][i])maxn = dp[1][i];
			if (maxn < dp[0][i])maxn = dp[0][i];
		}
		
		cout << maxn << "\n";
	}



}