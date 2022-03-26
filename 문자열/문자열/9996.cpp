#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int k = s.find("*");
	string s1 = s.substr(0, k);
	string s2 = s.substr(k + 1, s.size() - k - 1);

	while (n--) {
		int flag = 1;
		string str;
		cin >> str;

		if (str.size() + 1 < s.size()) {
			cout << "NE\n";
			continue;
		}

		string str1 = str.substr(0, k);
		string str2 = str.substr(str.size() - s.size() + k + 1, s.size() - k - 1);

		if (s1 != str1)flag = 0;
		if (s2 != str2)flag = 0;


		if (flag)cout << "DA\n";
		else cout << "NE\n";
	}

}