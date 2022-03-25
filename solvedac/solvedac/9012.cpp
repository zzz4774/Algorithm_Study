#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		stack<char> s;
		string str;

		cin >> str;
		int flag = 1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')s.push('(');

			if (str[i] == ')') {
				if (s.empty()) {
					flag = 0;
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (!s.empty())flag = 0;
		if (!flag)cout << "NO\n";
		else cout << "YES\n";
	}
}