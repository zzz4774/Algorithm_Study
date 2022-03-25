#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;

	int result = -1;
	int div5 = 0;
	int div3 = 0;

	div5 = n / 5;
	for (int i = div5; i >= 0; i--) {
		if ((n - (i * 5)) % 3 == 0) {
			result = i + (n - (i * 5)) / 3;
			break;
		}
	}

	cout << result;
}