#include<iostream>
#include<algorithm>
using namespace std;
long long arr[100000];

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	int flag = 1;

	/*
	long long tmp;
	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	*/

	sort(arr + 1, arr + num);

	for (int i = 1; i < num; i++) {
		if (arr[0] < arr[i]) {
			flag = 0;
			break;
		}
		else {
			arr[0] += arr[i];
		}
	}
	if (flag)cout << "Yes";
	else cout << "No";
}