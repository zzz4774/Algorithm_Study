#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
struct node {
	ll x;
	int y;
};
priority_queue<node> pq;
bool operator<(node x, node y) {
	if (abs(x.x) == abs(y.x))return x.y > y.y;
	return abs(x.x) > abs(y.x);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	while (n--) {
		ll a;
		cin >> a;
		if (a != 0) {
			node now;
			now.x = abs(a);
			if (a > 0)now.y = 1;
			else now.y = -1;
			pq.push(now);
		}
		else {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				node num = pq.top();
				pq.pop();
				cout << num.x * num.y << "\n";
			}
		}

	}
}