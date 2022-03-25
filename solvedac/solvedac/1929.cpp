#include<iostream>
#include<cmath>
using namespace std;
int m, n;
int arr[1000010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	//에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0)continue;
		for (int j = i * i; j <= n; j += i)
			arr[j] = 0;
	}


	for (int i = m; i <= n; i++) {
		if (arr[i] != 0)cout << arr[i] << "\n";
	}
}