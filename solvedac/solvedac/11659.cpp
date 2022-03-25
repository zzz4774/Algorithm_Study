#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[100001];
int sum[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sum[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}


	while (m--) {
		int start, end;
		cin >> start >> end;
		int num = sum[end] - sum[start - 1];
		cout << num << "\n";

	}
}