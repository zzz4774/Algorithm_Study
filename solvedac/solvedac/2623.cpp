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

	int n, k;
	cin >> n >> k;
	vector<int>cnt(n + 1);
	vector<vector<int>> v(n+1);

	while (k--) {
		int sNum;
		int s1, s2;
		cin >> sNum;
		if (sNum == 0) continue;
		cin >> s1;
		if (sNum == 1) continue;

		for (int i = 0; i < sNum - 1; i++) {
			cin >> s2;
			v[s1].push_back(s2);
			cnt[s2]++;
			s1 = s2;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)q.push(i);
		
	}

	vector<int>ans;
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		ans.push_back(s);

		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i];
			cnt[next]--;
			if (cnt[next] == 0) {
				q.push(next);
			}
		}
	}

	if (ans.size() != n) {
		cout << 0 << endl;
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << ans[i] << "\n";
		}
	}

}