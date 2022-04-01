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

	int n, m;
	cin >> n >> m;
	
	int minset = 10000;
	int minone = 10000;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < minset)minset = a;
		if (b < minone)minone = b;
	}

	int sum = 0;
	int x, y;
	x = n / 6;
	y = n % 6;
	
	if (minset > minone * 6) {
		sum = minone * n;
	}
	else if (minset < minone * y) {
		sum = minset * (x + 1);
	}
	else {
		sum = minset * x + minone * y;
	}

	cout << sum << endl;

}