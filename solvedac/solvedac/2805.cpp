#include<iostream>
#include<string>
using namespace std;
long long arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max)max = arr[i];
	}

	long long start = 0;
	long long mid;
	long long end = max;
	int ans = 0;

	while (end >= start) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long num = arr[i] - mid;
			if (num > 0)sum += num;
		}
		if (sum >= k) {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}