#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll a, b, c;

ll cal(ll a, ll b) {
	if (b == 0)return 0;
	else if (b == 1)return a;
	else if (b % 2 == 1) {
		return cal(a, b - 1) * a;
	}
	else {
		ll sum = cal(a, b / 2) % c;
		return (sum * sum) % c;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	
	

	ll num = cal(a, b);


	cout << num % c;

}