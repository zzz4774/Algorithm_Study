#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		int now = m / arr[i];
		m -= now * arr[i];
		cnt += now;
	}

	cout << cnt << "\n";

}