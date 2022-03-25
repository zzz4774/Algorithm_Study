#include<iostream>
using namespace std;

int main() {
	int arr[100] = { 0 };
	int len, num;

	cin >> len >> num;

	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	int sum;
	int max = 0;

	for (int i = 0; i < len - 2; i++) {
		for (int j = i+ 1; j < len - 1; j++) {
			for (int k = j+ 1; k < len; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum > max && sum <= num){ max = sum;
			}
		}
	}

	cout << max;
}