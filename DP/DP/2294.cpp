#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, k;
int arr[100];
int dp[20000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (m <= 10000) {
			arr[cnt] = m;
			dp[arr[cnt]] = 1;
			cnt++;
		}
	}

	sort(arr, arr + cnt);
	int c = k / arr[0];
	int num = 1;
	while (1) {
		for (int j = 1; j <= k; j++) {
			if (dp[j] == num) {
				for (int i = 0; i < cnt; i++) {
					if (j + arr[i] <= k && (dp[j + arr[i]] == 0 || dp[j + arr[i]] > num + 1)) {
						dp[j + arr[i]] = num + 1;
					}
				}
			}
		}

		if (num == c)break;
		if (dp[k] != 0)break;
		num++;

	}

	if (dp[k] == 0)cout << -1 << endl;
	else cout << dp[k] << endl;


}