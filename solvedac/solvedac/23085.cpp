#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct node {
	int h;
	int cnt;
};
queue<node> q;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> check(n+1);
	int hcnt = 0;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		if (a == 'H')hcnt++;
	}


	q.push({ hcnt, 0 });
	check[hcnt] = 1;

	int res = 0;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.h == 0) {
			cout << now.cnt << endl;
			return 0;
		}

		for (int i = 0; i <= k; i++) {
			if (now.h < i || (n - now.h) < k - i)continue;
			int next = now.h + k - 2 * i;
			if (check[next] == 1)continue;
			check[next] = 1;
			q.push({ next, now.cnt + 1 });
		}
	}

	cout << -1 << endl;
}