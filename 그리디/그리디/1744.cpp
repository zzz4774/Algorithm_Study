#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> plus;
	vector<int> minus;
	int flag = 0;
	int n;
	cin >> n;

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num > 0) {
			if (num == 1) {
				sum++;
			}
			else {
				plus.push_back(num);
			}
		}
		else if (num < 0)minus.push_back(num);
		else if (num == 0)flag = 1;
	}

	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());

	if (!plus.empty()) {
		if (plus.size() == 1) {
			sum += plus[0];
		}
		else {
			if (plus.size() % 2 == 0) {
				for (int i = 0; i < plus.size() - 1; i += 2) {
					sum += plus[i] * plus[i + 1];
				}
			}
			else {
				for (int i = 0; i < plus.size() - 2; i += 2) {
					sum += plus[i] * plus[i + 1];
				}
				sum += plus[plus.size() - 1];
			}
		}
	}
	
	if (!minus.empty()) {
		if (minus.size() == 1) {
			if (!flag)sum += minus[0];
		}
		else {
			if (minus.size() % 2 == 0) {
				for (int i = 0; i < minus.size() - 1; i += 2) {
					sum += minus[i] * minus[i + 1];
				}
			}
			else {
				for (int i = 0; i < minus.size() - 2; i += 2) {
					sum += minus[i] * minus[i + 1];
				}
				if (flag == 0) {
					sum += minus[minus.size() - 1];
				}
			}

		}
	}
	

	cout << sum << endl;
}