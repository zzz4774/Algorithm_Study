#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int end;
		cin >> end;
		priority_queue<int, vector<int>, greater<int>>q;
		int cnt= 0;
		q.push(0);

		while (!q.empty()) {
			int now = q.top();
			q.pop();
			if (now == end) {
				cnt++;
			}
			else if (now > end) {
				break;
			}

			int a1 = now + 1;
			q.push(a1);

			int a2 = now + 2;
			q.push(a2);

			int a3 = now + 3;
			q.push(a3);

		}
		cout << cnt << "\n";
	}
}