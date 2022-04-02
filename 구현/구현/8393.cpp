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
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum << endl;
}