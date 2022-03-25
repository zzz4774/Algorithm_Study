#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	int m;
	cin >> n >> m;
	string str;
	cin >> str;


	int cnt = 0;
	for (int i = 1; i < m; i++) {
		int k = 0;
		if (str[i-1] != 'I')continue;
		while (str[i] == 'O' && str[i + 1] == 'I') {
			i += 2;
			k++;
			if (k == n) {
				k--;
				cnt++;
			}
		}
	}
	cout << cnt << endl;

}