#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, int> map;
		while (n--) {
			string a, b;
			cin >> a >> b;
			if (map.find(b) == map.end()) {
				map.insert({ b,1 });
			}
			else {
				map[b]++;
			}
		}
		int ans = 1;
		for (auto i : map) {
			ans *= (i.second + 1);
		}
		ans--;
		cout << ans << '\n';
	}

}