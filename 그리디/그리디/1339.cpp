#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<string> v;
ll alpa[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int maxlen = 0;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (maxlen < str.size())maxlen = str.size();
		v.push_back(str);
	}

	for (int i = 0; i < n; i++) {
		string tmp = "";
		for (int j = 0; j < maxlen - v[i].size(); j++) {
			tmp += "0";
		}
		v[i] = tmp + v[i];
	}

	int num = 1;
	for (int i = maxlen - 1; i >= 0; i--) {
		
		for (int j = 0; j < n; j++) {
			alpa[v[j][i] - 'A'] += num;
		}
		num *= 10;
	}

	int k = 9;
	while (1) {
		int maxn = 0;
		int maxindex = -1 ;
		for (int i = 0; i < 26; i++) {
			if (maxn < alpa[i]) {
				maxn = alpa[i];
				maxindex = i;
			}
		}
		if (maxindex == -1)break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < maxlen; j++) {
				if (v[i][j] == char('A' + maxindex))v[i][j] = char('0' + k);
			}
		}

		alpa[maxindex] = 0;
		k--;
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += stoi(v[i]);
	}

	cout << sum << endl;
}
