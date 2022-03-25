#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long int arr[100000];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		cin >> arr[i];
	}

	int start = 0;
	int end = n - 1;
	long long int max = 2000000000;
	long long int a = 0;
	long long int b = 0;
	while (start < end) {
		long long int val = arr[start] + arr[end];
		if (abs(val) < max) {
			max = abs(val);
			a = arr[start];
			b = arr[end];
		}


		if (val > 0) {
			end -= 1;
		}
		else{
			start += 1;
		}
		

		

	}

	cout << a << " " << b << endl;
}