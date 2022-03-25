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
	priority_queue<int> q;

	while (n--) {
		int com;
		cin >> com;

		if (com == 0) {
			if (q.empty())cout << 0 << '\n';
			else {
				int now = q.top();
				cout << now << "\n";
				q.pop();
			}
		}
		else {
			q.push(com);
		}
	}

}