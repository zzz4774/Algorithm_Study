#include<iostream>
#include<string>
using namespace std;
int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1)continue;
		int flag = 1;
		for (int j = 2; j <= arr[i] - 1; j++) {
			if (arr[i] % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)cnt++;
	}
	cout << cnt;
}