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

	int n;
	cin >> n;
	vector<int> v(n + 1);
	vector<int>used(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {

		for (int j = 1; j <= n; j++) {
			if (v[j] == 0 && used[j] == 0) {
				vec[i] = j;
				used[j] = 1;
				break;
			}
			else if (v[j] != 0) {
				v[j]--;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}