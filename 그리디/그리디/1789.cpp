#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	ll res = 0;
	ll sum = 0;
	for (int i = 1; i < 90000000; i++) {
		sum+=i;
		if (sum + i + 1 > n) {
			res = i;
			break;
		}
	}

	cout << res << endl;
}