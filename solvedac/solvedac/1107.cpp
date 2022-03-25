#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int dat[10];

int check(int now) {
	string str = to_string(now);
	for (int i = 0; i < str.size(); i++) {
		if (dat[int(str[i] - '0')] != 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		dat[a] = 1;
	}

	int cnt = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = abs(n - i) + to_string(i).size();
			cnt = min(cnt, tmp);
		}
	}

	cout << cnt << endl;

}