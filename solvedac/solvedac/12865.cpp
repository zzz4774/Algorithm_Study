#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct node {
	int weight;
	int value;
};
int dp[100][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<node>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].weight >> v[i].value;
	}

	for (int i = 0; i < k; i++) {
		if (i >= v[0].weight - 1)dp[0][i] = v[0].value;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (j >= v[i].weight - 1)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].weight] + v[i].value);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n - 1][k - 1] << endl;

}