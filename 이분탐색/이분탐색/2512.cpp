#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[10000];
int n, m;
int maxv = 0;
int per(int x) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			sum += arr[i];
		}
		else sum += x;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (maxv < arr[i])maxv = arr[i];
	}
	cin >> m;


	int start = 1;
	int end = maxv;
	int mid;
	int res=0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (per(mid) > m) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			if (res < mid)res = mid;
		}

	}
	cout << res << endl;
}