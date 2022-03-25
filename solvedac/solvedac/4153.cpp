#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0)break;

		if (x > z)swap(x, z);
		if (y > z)swap(y, z);
		if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
			cout << "right\n";
		}
		else cout << "wrong\n";
	}

}