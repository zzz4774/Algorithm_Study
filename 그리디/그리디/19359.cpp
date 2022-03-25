#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a = 0;
	int b = 0;

	vector <int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		a += arr[i] / 2;
		b += arr[i] % 2;
	}

	if ((a - b) % 3 == 0 && a >= b) {
		cout << "YES";
	}
	else cout << "NO";

	return 0;
}






//#include<iostream>
//#include<string>
//using namespace std;
//int n;
//int arr[100000];
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	int flag = 0;
//
//	long long sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += arr[i];
//	}
//
//	long long d = 0;
//	if (sum == 0)flag = 1;
//	else {
//
//		
//		for (int i = 0; i < n; i++) {
//			int k = arr[i] / 2;
//			d += k * 2;
//			sum -= k * 2;
//			if (d >= sum) {
//				if ((d - sum) % 3 == 0 && d/2 >= sum) {
//					flag = 1;
//
//				}
//			}
//			
//			
//
//		}
//	}
//
//
//	if (flag)cout << "YES";
//	else cout << "NO";
//
//}