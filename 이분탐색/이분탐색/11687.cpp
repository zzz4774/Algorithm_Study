#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int find(long long int a) {
	long long int cnt = 0;
	long long int x = 5;
	while (a >= x) {
		cnt += a / x;
		x = x * 5;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m;
	long long int start = 0;
	long long int end = 5000000000;
	long long int mid;
	long long int res = 5000000000;
	while (start <= end) {
		mid = (start + end) / 2;
		if (find(mid) < m) {
			start = mid + 1;
		}
		else if(find(mid) > m) {
			end = mid - 1;
		}
		else {
			end = mid - 1;
			if (res > mid)res = mid;
		}
	}
	if (res == 5000000000)cout << -1;
	else cout << res << endl;

}