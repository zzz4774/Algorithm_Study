#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	vector<int> dp(n);
	dp[0] = v[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				if (dp[i] < dp[j])dp[i] = dp[j];
			}
		}
		dp[i] += v[i];
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i])max = dp[i];
	}

	cout << max << endl;
	
}