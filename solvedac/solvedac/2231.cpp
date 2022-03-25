#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i < n; i++) {
		int num = i;
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			num += (int)(str[j] - '0');
		}

		if (num == n) {
			res = i;
			break;
		}

	}
	cout << res << endl;
}