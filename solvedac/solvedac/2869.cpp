#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, v;
	cin >> a >> b >> v;
	long long now = 0;
	long long day = 0;

	if ((v - a) % (a - b) == 0)day = (v - a) / (a - b) + 1;
	else day = (v - a) / (a - b) + 2;

	cout << day << endl;
}