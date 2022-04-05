#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

ll dp[100001];
ll arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}


	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = arr[i]; j <= k; j++){
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}
	cout << dp[k] << endl;


}