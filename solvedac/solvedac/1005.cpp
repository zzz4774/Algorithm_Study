#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> time( n+1 );
		vector<int> dp(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		vector<vector<int>> v(n+1);
		vector<int> cnt(n + 1);
		
		for (int i = 0; i < k; i++) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			cnt[to]++;
		}

		int last;
		cin >> last;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 0) {
				q.push(i);
			}
			dp[i] = time[i];
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];
				cnt[next]--;
				dp[next] = max(dp[now] + time[next], dp[next]);

				if (cnt[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << dp[last] << "\n";

	}


}