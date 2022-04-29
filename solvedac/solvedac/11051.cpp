#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

    for (int n_row = 1; n_row <= n; n_row++) {
        for (int k_col = 0; k_col <= n; k_col++) {
            if (n_row == k_col || k_col == 0) {
                dp[n_row][k_col] = 1;
                continue;
            }
            dp[n_row][k_col] = (dp[n_row - 1][k_col] + dp[n_row - 1][k_col - 1]) % 10007;
        }
    }

    cout << dp[n][k] <<endl;

}