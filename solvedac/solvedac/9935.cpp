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
	string s;
	string ans= "";

	cin >> str >> s;
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) {
		ans += str[i];

		if (ans[ans.size() - 1] == s[s.size() - 1] && ans.size() >= s.size()) {
			int cnt = 1;
			for (int j = s.size() - 2; j >= 0; j--) {
				if (ans[ans.size() - s.size() + j] == s[j])cnt++;
			}


			if (cnt == s.size()) {
				for (int k = 0; k < s.size(); k++) {
					ans.pop_back();
				}
			}
		}
	}


	if (ans == "")cout << "FRULA" << endl;
	else cout << ans << endl;

}