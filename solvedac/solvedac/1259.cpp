#include<iostream>
#include<string>
using namespace std;
string str;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> str;
		if (!stoi(str))break;

		int flag = 1;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != str[str.size() - i - 1])flag = 0;
		}
		if (flag)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}