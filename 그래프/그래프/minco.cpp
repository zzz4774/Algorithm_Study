#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n;
int num[100];
string path[100];
string act[4] = { "!!","#","$","&" };
int cnt;


int calc(int a, int b, string s) {
	if (s == "!!") {
		return((a - b) * (a + b));
	}
	else if (s == "#") {
		if (a > b)return a;
		else return b;
	}
	else if (s == "$") {
		return (a * a - b * b);
	}
	else if (s == "&") {
		return (a + b) * (a + b);
	}
}

void dfs(int lv) {
	if (lv == n - 1) {
		int start = num[0];
		for (int i = 0; i < n - 1; i++) {
			start = calc(start, num[i + 1], path[i]);
		}
		if (start == 100)cnt++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		path[lv] = act[i];
		dfs(lv + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	dfs(0);
	cout << cnt << endl;
}

