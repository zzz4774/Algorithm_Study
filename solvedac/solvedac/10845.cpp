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
	queue<int> q;

	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else if (str == "pop") {
			if (q.empty())cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size")cout << q.size() << "\n";
		else if (str == "empty") {
			if (q.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "front") {
			if (q.empty())cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty())cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}

}