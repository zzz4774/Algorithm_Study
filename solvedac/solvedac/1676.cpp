#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int n = i;
		while (1) {
			if (n % 5 != 0)break;
			n = n / 5;
			cnt++;
		}
	}
	cout << cnt << endl;
}