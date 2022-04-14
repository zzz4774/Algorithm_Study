#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
string s, t;
int flag;

void dfs(string now) {
	if (flag)return;

	if (now == s) {
		flag = 1;
		return;
	}

	if (now.size() < s.size())return;

	string next1, next2;
	if (now[now.size() - 1] == 'A') {
		for (int i = 0; i < now.size()-1; i++) {
			next1 += now[i];
		}
		dfs(next1);
	}

	if (now[0] == 'B') {
		for (int i = now.size() - 1; i >= 1; i--) {
			next2 += now[i];
		}
		dfs(next2);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> s >> t;
	dfs(t);

	if (flag)cout << 1 << endl;
	else cout << 0 << endl;

}