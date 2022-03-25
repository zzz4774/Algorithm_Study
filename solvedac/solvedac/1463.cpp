#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;

	arr[1] = 1;
	int n = 1;

	while (1) {

		for (int i = 1; i <= num; i++) {
			if (arr[i] == n) {
				if (i * 3 <= num) {
					if (arr[i * 3] == 0)arr[i * 3] = n + 1;
				}
				if (i * 2 <= num) {
					if (arr[i * 2] == 0)arr[i * 2] = n + 1;
				}
				if (i + 1 <= num) {
					if (arr[i + 1] == 0)arr[i + 1] = n + 1;
				}
				
			}
			
		}

		if (arr[num] != 0)break;
		n++;
	}

	cout << arr[num]-1 << endl;
}