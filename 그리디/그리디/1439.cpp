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

	string str;
	int cnt1 = 0;
	int cnt2 = 0;

	cin >> str;
	string str2 = str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			cnt1++;
			for (int j = i; j < str.size(); j++) {
				if (str[j] == '0')break;
				else str[j] = '0';
			}
		}
	}

	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] == '0') {
			cnt2++;
			for (int j = i; j < str2.size(); j++) {
				if (str2[j] == '1')break;
				else str2[j] = '1';
			}
		}
	}

	if (cnt1 > cnt2)cout << cnt2 << endl;
	else cout << cnt1 << endl;
}