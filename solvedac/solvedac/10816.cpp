#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector <int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);

	}

	sort(v.begin(), v.end());
	int m;
	cin >> m;

	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		auto upper = upper_bound(v.begin(), v.end(), num);
		auto lower = lower_bound(v.begin(), v.end(), num);
		ans.push_back(upper - lower);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}



}