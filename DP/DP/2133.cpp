#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= 30; i = i + 2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j = j - 2)
		{
			dp[i] = dp[i] + (dp[j] * 2);
		}
	}


	int n;
	cin >> n;
	cout << dp[n] << endl;
}