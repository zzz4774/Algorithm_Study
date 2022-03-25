#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int max = 0;
	vector<int> pl, mi;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0)pl.push_back(a);
		else mi.push_back(-a);
		if (max < abs(a))max = abs(a);
	}

	sort(mi.begin(), mi.end(), greater<>());
	sort(pl.begin(), pl.end(), greater<>());
	int sum = 0;
	for (int i = 0; i < pl.size(); i += m)sum += pl[i] * 2;
	for (int i = 0; i < mi.size(); i += m)sum += mi[i] * 2;

	cout << sum - max << endl;



}