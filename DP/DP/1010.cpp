#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int arr[31];
int dp[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;

		ll sum = 1;

		for (int i = 1; i <= a; i++) {
			arr[i] = 1;
		}

		for (int i = b; i >= b-a+1; i--) {
			dp[i] = 1;
		}

		for (int i = 30; i >= 1; i--) {
			if (dp[i] == 1) {
				dp[i] = 0;
				sum *= i;

				for (int j = 30; j >= 1; j--) {
					if (arr[j] == 1 && sum % j == 0) {
						sum /= j;
						arr[j] = 0;
					}
				}
			}
		}

		cout << sum << "\n";

	}
}