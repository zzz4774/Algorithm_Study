#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[40000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int flag = 1;
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int bignum=0;
		int smallnum=0;

		for (int i = 1; i < n + m;i++) {
			if (n % i == 0 && m % i == 0)smallnum = i;
		}
		bignum = m * n / smallnum;


		int xnum = 0;
		int ynum = 0;

		while (1) {
			if ((xnum * m) + x >= bignum || (ynum * n) + y >= bignum) {
				flag = 0;
				break;
			}

			if ((xnum * m) + x == (ynum * n) + y)break;
			else if ((xnum * m) + x > (ynum * n) + y) {
				ynum++;
			}
			else if ((xnum * m) + x < (ynum * n) + y) {
				xnum++;
			}
		}
		if (flag)cout << (xnum * m) + x << "\n";
		else cout << -1 << "\n";

	}

}