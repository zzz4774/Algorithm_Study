#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[302];
int used[302];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	used[0] = arr[0];
	used[1] = arr[0] + arr[1];
	if (arr[0] + arr[2] > arr[1] + arr[2]) {
		used[2] = arr[0] + arr[2];
	}
	else used[2] = arr[1] + arr[2];

	for (int i = 3; i < n; i++) {
		if (used[i - 2] + arr[i] <= used[i - 3] + arr[i - 1] + arr[i])used[i] = used[i - 3] + arr[i - 1] + arr[i];
		else used[i] = used[i - 2] + arr[i];
	}
	cout << used[n - 1] << endl;





}