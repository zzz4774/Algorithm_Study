#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	vector<int>v(n + 1);
	vector<int>res;
	for (int i = 2; i <= n; i++) {
		v[i] = i;
	}

	//에라토스테네스의 체
	for (int i = 2; i <= sqrt(n); i++) {
		if (v[i] == 0)continue;
		else {
			for (int j = i * i; j <= n; j += i) {
				v[j] = 0;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (v[i] != 0) {
			res.push_back(i);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		int sum = 0;
		for (int j = i; j < res.size(); j++) {
			sum += res[j];
			if (sum == n)cnt++;
			else if (sum > n)break;
		}
	}


	cout << cnt << endl;


}