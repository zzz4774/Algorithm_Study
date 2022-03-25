#include<iostream>
#include<vector>
using namespace std;
char v[500001];

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cntR = 0;
	int cntB = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == 'R')cntR++;
		else cntB++;
	}


	if (cntR == 0 || cntB == 0) {
		cout << 0;
	}
	else {

		int cnt = 0;
		if (v[n - 1] == 'R') {
			for (int i = n - 1; i >= 0; i--) {
				if (v[i] == 'B')break;
				else cnt++;
			}

			if (cntR - cnt > cntB) {
				cout << cntB;
			}
			else cout << cntR - cnt;

		}
		if (v[n - 1] == 'B') {
			for (int i = n - 1; i >= 0; i--) {
				if (v[i] == 'R')break;
				else cnt++;
			}

			if (cntB - cnt > cntR) {
				cout << cntR;
			}
			else cout << cntB - cnt;

		}
	}
}