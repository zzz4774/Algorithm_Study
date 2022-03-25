#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
string str[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map <string, int>map;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		map.insert(make_pair(str[i], i + 1));
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (s[0]>='0' && s[0]<='9') {
			cout << str[stoi(s)-1] << "\n";
		}
		else {
			auto where = map.find(s);
			cout << where->second << "\n";
		}
	}

}