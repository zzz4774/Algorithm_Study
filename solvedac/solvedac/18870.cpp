#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	arr = vector<int>(n);
	res = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		res[i] = arr[i];
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (int i = 0; i < n; i++) {
		auto wh = lower_bound(res.begin(), res.end(), arr[i]);

		cout << wh - res.begin() << " ";
	}

}