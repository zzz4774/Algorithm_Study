#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int>v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = v[n - 1] - 1;
	int mid;
	int res = 0;

	while (start <= end) {
		int install = 1;
		int mid = (start + end) / 2;



		int first = v[0];
		for (int i = 1; i < n; i++) {
			int last = v[i];

			if (last - first >= mid) {
				install++;
				first = last;
			}
		}



		if (install >= k) {
			res = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}



	}

	cout << res << endl;
}