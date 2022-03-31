#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int> v;
int n, s;
int sum;
int cnt = 0;

void dfs(int lv) {
	if (lv == n) {
		if (sum == s)cnt++;
		return;
	}


	dfs(lv + 1);
	sum += v[lv];
	dfs(lv + 1);
	sum -= v[lv];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> s;
	

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	dfs(0);
	if (s == 0)cnt -= 1;
	cout << cnt << endl;
}