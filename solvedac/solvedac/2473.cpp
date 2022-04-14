#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int a, b, c;
	ll sum = 0;
	ll x = 0;
	ll y = 0;
	ll z = 0;
	ll min = 3000000001;

	sort(v.begin(), v.end());
	for (int i = 0; i < n-2; i++) {
		a = i;
		b = i + 1;
		c = n - 1;
		while (c > b) {
			sum = v[a] + v[b] + v[c];
			if (min > abs(sum)) {
				min = abs(sum);
				x = v[a];
				y = v[b];
				z = v[c];
			}
			

			if (abs(v[a] + v[b + 1] + v[c]) < abs(v[a] + v[b] + v[c-1])) {
				b += 1;
				continue;
			}
			else {
				c -= 1;
				continue;
			}
			
		}
	}

	cout << x << " " << y << " " << z << endl;
}