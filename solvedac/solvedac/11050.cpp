#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int fact(int x) {
	int num = 1;
	for (int i = 1; i <= x; i++) {
		num*= i;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int a, b, c;
	a = fact(n);
	b = fact(k);
	c = fact(n - k);

	cout << a / (b * c) << endl;
}