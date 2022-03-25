#include<iostream>
#include<string>
using namespace std;
int arr[15][15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i <= 14; i++) {
		arr[14][i] = i + 1;
	}

	for (int i = 13; i >=0; i--) {
		for (int j = 0; j <= 14; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i + 1][k];
			}
		}
	}

	while (n--) {
		int k, val;
		cin >> k >> val;
		cout << arr[14-k][val-1]<<endl;

	}

}