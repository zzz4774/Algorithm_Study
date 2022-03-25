#include<iostream>
using namespace std;

int main() {
	int arr[9] = {0};
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	int x, y;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j)
					sum += arr[k];

			}
			if (sum == 100) {
				x = i;
				y = j;
				break;
			}
			else {
				sum = 0;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != x && i != y) {
			cout << arr[i] << endl;
		}
	}
}