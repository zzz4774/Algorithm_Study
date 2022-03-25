#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int dat[10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dat[num]++;
	}


	for (int i = 0; i < 10001; i++) {
		if (dat[i] != 0) {
			while (dat[i]--) {
				cout << i << "\n";
			}
		}
	}



}