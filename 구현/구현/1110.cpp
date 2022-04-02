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
	
	int cnt = 0;
	int k;;
	int num = n;
	while (1) {
		k = num % 10 + num / 10;

		num = num % 10 * 10 + k % 10;
		cnt++;
		if (num == n)break;

	}
	cout << cnt << endl;
}