#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int arr[50001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	arr[1] = 1;

	
	for (int i = 2; i <= n; i++) {
		int minn = 100000;
		for (int j = 1; j*j <= i; j++) {
			int tmp = i - j * j;
			minn = min(minn, arr[tmp]);
		}
		arr[i] = minn + 1;
	}


	cout << arr[n] << endl;
}