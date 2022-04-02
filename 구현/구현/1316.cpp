#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int dat[200];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int cnt = 0;

	while (n--) {
		string str;
		cin >> str;
		int flag = 1;
		for (int i = 0; i < str.size()-1; i++) {
			if (str[i] == str[i + 1])continue;
			if (dat[str[i]] == 1) {
				flag = 0;
				break;
			}
			dat[str[i]] = 1;
		}
		if (dat[str[str.size() - 1]] == 1)flag = 0;

		if (flag)cnt++;

		for(int i = 0; i < 200; i++) {
			dat[i] = 0;
		}
	}


	cout << cnt << endl;
}