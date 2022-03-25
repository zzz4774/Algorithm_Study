#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	arr[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (i % 2 == 0)arr[i] = (arr[i - 1] * 2 + 1) % 10007;
		else arr[i] = (arr[i - 1] * 2 - 1)%10007;
	}
	int n;
	cin >> n;
	cout << arr[n] << endl;

}