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

	int num = 1;
	while (1) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)break;

		int cnt = 0;

		cnt += (v / p) * l;
		if (v % p >= l)cnt += l;
		else cnt += v % p;
		cout << "Case "<< num <<": "<< cnt << "\n";
		num++;
	}

}