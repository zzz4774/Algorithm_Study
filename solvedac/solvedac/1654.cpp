#include<iostream>
#include<string>
using namespace std;
long long arr[10000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	long long max = 0;
	for (int i = 0; i < k; i++) {
		if (max < arr[i])max = arr[i];
	}

	int res = 0;
	long long mid, low=1;

	// 이진 탐색 사용
	while (low <= max) {
		mid = (low + max) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}


		if (cnt < n) max = mid - 1;
		else {
			low = mid + 1;
			if (res < mid)res = mid;
		}


	}

	cout << res;
}
