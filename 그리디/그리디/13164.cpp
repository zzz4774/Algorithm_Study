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
	int num = n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dis(n - 1);
	for (int i = 0; i < n - 1;i++) {
		dis[i] = v[i + 1] - v[i];
	}

	sort(dis.begin(), dis.end(), less<>());
	int sum = 0;
	for (int i = 0; i < dis.size() - m + 1; i++) {
		sum += dis[i];
	}

	cout << sum << endl;

	

}