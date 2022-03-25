#include<iostream>
#include<string>
using namespace std;
int map[100][100];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int h, w, lv;
		cin >> h >> w >> lv;

		int a = lv / h;
		int b = lv % h;
		if (b == 0)cout << (h * 100) + a << "\n";
		else cout << b * 100 + (a + 1) << "\n";
	}
}