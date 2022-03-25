#include<iostream>
#include<string>
using namespace std;
int a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = a + b; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << endl;
			break;
		}
	}



	for (int i = a; i < 100000000; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i << endl;
			break;
		}
	}

}



