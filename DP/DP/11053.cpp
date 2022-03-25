#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int arr[1000];
int dp[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int maxn = -1;

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--){
			if (arr[i] > arr[j])dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] > maxn)maxn = dp[i];
	}

	cout << maxn << endl;
	
}