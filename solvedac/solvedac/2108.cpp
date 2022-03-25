#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[500000];
int dat[10000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	double sum = 0;
	double max = -5000;
	double min = 5000;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max)max = arr[i];
		if (arr[i] < min)min = arr[i];
		dat[arr[i] + 4000]++;
	}


	double axsum = sum / n;
	if (round(axsum) == -0)axsum = 0;
	cout << round(axsum) << endl;



	sort(arr, arr + n);
	cout << arr[(n / 2)] << endl;


	int maxindex;
	int maxval = 0;
	int st = 0;
	for (int i = 0; i <= 8000; i++) {
		if (maxval < dat[i]) {
			maxval = dat[i];
			maxindex = i;
		}
	}

	for (int i = 0; i <= 8000; i++) {
		if (maxval == dat[i]) {
			if (st > 1)break;
			maxindex = i;
			st++;
		}
	}


	cout << maxindex - 4000 << endl;



	cout << max - min << endl;

}