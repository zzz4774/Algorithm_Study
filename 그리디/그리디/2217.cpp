#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum < arr[i] * (n - i)) sum = arr[i] * (n - i);
	}

	cout << sum << endl;


}