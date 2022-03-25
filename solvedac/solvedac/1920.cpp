#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long arr[100001];
int n;
int m;

void bs(int key) {
	int start = 0;
	int mid;
	int end = n - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] > key)end = mid - 1;
		else start = mid + 1;
	}
	cout << 0 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);


	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		bs(tmp);
	}
	return 0;
}