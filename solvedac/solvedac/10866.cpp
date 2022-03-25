#include<iostream>
#include<algorithm>
#include<string>
#include<deque>;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> d;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (str == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (str == "pop_front") {
			if (d.empty())cout << -1 << "\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (d.empty())cout << -1 << "\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (str == "size")cout << d.size() << "\n";
		else if (str == "empty") {
			if (d.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "front") {
			if (d.empty())cout << -1 << "\n";
			else {
				cout << d.front() << "\n";
			}
		}
		else if (str == "back") {
			if (d.empty())cout << -1 << "\n";
			else {
				cout << d.back() << "\n";
			}
		}
	}


}