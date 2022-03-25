#include<iostream>
using namespace std;

int main() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	int result;
	int cnt = 0;

	for (int i = 1; i < 1000000; i++) {
		for (int j = 0; j < 5; j++) {
			if (i % arr[j] == 0)cnt++;
		}
		if (cnt >= 3) {
			result = i;
			break;
		}
		else cnt = 0;
	}
	cout << result;
}