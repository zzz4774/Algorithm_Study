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

	int e = 1;
	int s = 1;
	int m = 1;
	int n = 1;

	int a, b, c;
	cin >> a >> b >> c;

	while (1) {
		if ((a == e) && (s == b) && (m == c))break;
		e++;
		if (e == 16)e = 1;
		s++;
		if (s == 29)s = 1;
		m++;
		if (m == 20)m = 1;
		n++;
	}

	cout << n << endl;
}