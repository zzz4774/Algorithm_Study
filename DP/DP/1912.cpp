#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int arr[100000];
int dp[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(arr[i] + dp[i - 1], arr[i]);
	}

	int maxn = -10000001;
	for (int i = 0; i < n; i++) {
		if (maxn < dp[i])maxn = dp[i];
	}
	cout << maxn<<endl;


}