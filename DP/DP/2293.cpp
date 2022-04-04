#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int dp[100001];
int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i + arr[j] > 100001)continue;
			dp[i + arr[j]] += dp[i];
		}
	}

	cout << dp[k] << endl;
}