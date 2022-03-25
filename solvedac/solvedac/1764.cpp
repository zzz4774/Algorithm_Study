#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> map;
	vector<string>v;

	for (int i = 0; i < n+m; i++) {
		string s;
		cin >> s;
		map[s]++;
		if (map[s]>1) {
			v.push_back(s);
		}
		
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}