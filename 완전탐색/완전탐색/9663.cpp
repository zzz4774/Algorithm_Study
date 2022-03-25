#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int q[15];
int n;
int cnt;

void dfs(int now) {
	if (now == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < now && flag; j++) {
			if (q[j] == i || abs(q[j] - i) == now - j)flag = 0;
		}
		if (!flag)continue;
		q[now] = i;
		dfs(now+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dfs(0);
	cout << cnt << endl;
}