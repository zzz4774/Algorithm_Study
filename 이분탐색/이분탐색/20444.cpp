#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int n;
	long long int k;
	cin >> n >> k;
	
	long long int start = 0;
	long long int end = n / 2;
	long long int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if ((mid+1) * (n + 1 - mid) > k) {
			end = mid - 1;
		}
		else if ((mid + 1) * (n + 1 - mid) < k) {
			start = mid + 1;
		}
		else if ((mid + 1) * (n + 1 - mid) == k) {
			cout << "YES" << endl;
			return 0;
		}

	}
	cout << "NO" << endl;;
	return 0;
}