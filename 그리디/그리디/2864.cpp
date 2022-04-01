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

	string a, b;
	cin >> a >> b;

	string a1, a2, b1, b2;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '5')a1 += '6';
		else a1 += a[i];

		if (a[i] == '6')a2 += '5';
		else a2 += a[i];
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '5')b1 += '6';
		else b1 += b[i];

		if (b[i] == '6')b2 += '5';
		else b2 += b[i];
	}

	cout << stoi(a2) + stoi(b2) << " " << stoi(a1) + stoi(b1) << endl;
}