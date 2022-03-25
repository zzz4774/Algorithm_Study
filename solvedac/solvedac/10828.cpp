#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack <int> s;
	int n;
	cin >> n;
	while (n--) {
		string command;
		cin >> command;
		if (command == "push") {
			int k;
			cin >> k;
			s.push(k);
		}
		else if (command == "top") {
			if (s.empty())cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
		else if (command == "pop") {
			if (s.empty())cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (command == "size")cout << s.size() << "\n";
		else if (command == "empty") {
			if (s.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}


}