#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long hvalue;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		int k = int(str[i] - 'a' + 1);
		long long r = 1;
		for (int j = 0; j < i; j++) {
			r *= 31;
			if (r >= 1234567891)r %= 1234567891;
		}
		hvalue += k * r;
	}

	cout << hvalue % 1234567891 << "\n";
}