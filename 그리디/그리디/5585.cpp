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

	int n;
	cin >> n;
	int res = 1000 - n;

	int sum = 0;
	sum += res / 500;
	res = res % 500;

	sum += res / 100;
	res = res % 100;

	sum += res / 50;
	res = res % 50;

	sum += res / 10;
	res = res % 10;

	sum += res / 5;
	res = res % 5;

	sum += res;

	cout << sum << endl;
}