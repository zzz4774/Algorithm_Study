#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int arr[1000];
int dp[1000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = 1;
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k] && dp[i][0] <= dp[k][0])dp[i][0] = dp[k][0] + 1;
		}
	}

	dp[n-1][1] = 1;
	for (int i = n-2; i >=0; i--) {
		dp[i][1] = 1;
		for (int k = n-1; k > i; k--) {
			if (arr[i] > arr[k] && dp[i][1] <= dp[k][1])dp[i][1] = dp[k][1] + 1;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < (dp[i][0] + dp[i][1]))max = (dp[i][0] + dp[i][1]);
	}

	cout << max - 1 <<endl;
}