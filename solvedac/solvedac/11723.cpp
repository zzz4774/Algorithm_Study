#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "add") {
			int num;
			cin >> num;
			if (arr[num] == 0)arr[num] = 1;
		}
		else if (str == "remove") {
			int num;
			cin >> num;
			if (arr[num] == 1)arr[num] = 0;
		}
		else if (str == "check") {
			int num;
			cin >> num;
			if (arr[num] == 1)cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "toggle") {
			int num;
			cin >> num;
			if (arr[num] == 1)arr[num] = 0;
			else arr[num] = 1;
		}
		else if (str == "all") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 1;
			}
		}
		else if (str == "empty") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 0;
			}
		}
	}

}