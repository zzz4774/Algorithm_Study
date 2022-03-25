#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		if (i < 100)cnt++;
		else {
			a = i / 100;
			b = (i - (a * 100)) / 10;
			c = i % 10;

			if ((a - b) == (b - c))cnt++;
		}
	}

	cout << cnt;
}