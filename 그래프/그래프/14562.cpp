#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct node {
	int s;
	int t;
	int cnt;
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		queue<node>q;
		int s, t;
		cin >> s >> t;
		q.push({ s,t,0 });
		int cnt = 0;

		while (!q.empty()) {
			node now = q.front();
			q.pop();
			if (now.s == now.t) {
				cnt = now.cnt;
				break;
			}
			if (now.s > now.t) {
				continue;
			}

			cnt++;
			q.push({ now.s + 1,now.t, now.cnt+1 });
			q.push({ now.s * 2,now.t + 3, now.cnt+1 });
		}
		cout << cnt << "\n";
		

	}
}