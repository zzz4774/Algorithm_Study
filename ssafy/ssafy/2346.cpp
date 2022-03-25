#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> a >> b >> c;

	cout << (a + b) % c << endl;
	cout << ((a%c)+(b%c))%c << endl;

	cout << (a * b) % c << endl;
	cout << (a * b) % c << endl;
}