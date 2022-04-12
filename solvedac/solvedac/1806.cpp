#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll s;
	cin >> n >> s;
	ll sum = 0;
	ll cnt = 0;
	ll mincnt = 1000000001;
	int index = 0;
	v = vector<ll>(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int flag = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		cnt++;
		if (sum >= s) {
			index = i + 1;
			flag = 1;
			mincnt = cnt;
			break;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return 0;
	}
	
	cnt -= 1;
	sum -= v[0];

	for (int i = 1; i < n; i++) {
		flag = 0;

		if (sum >= s) {
			if (mincnt > cnt)mincnt = cnt;
			cnt -= 1;
			sum -= v[i];
			continue;
		}

		for (int j = index; j < n; j++) {
			sum += v[j];
			cnt++;
			if (sum >= s) {
				index = j + 1;
				flag = 1;
				break;
			}
		}
		if (flag) {
			if (mincnt > cnt)mincnt = cnt;
			cnt -= 1;
			sum -= v[i];
		}
		else break;
	}

	cout << mincnt << endl;
}