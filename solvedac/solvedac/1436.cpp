#include<iostream>
#include<string>
using namespace std;
long long arr[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a = 666;
	int cnt = 0;
	while (1) {
		if (arr[n - 1] != 0)break;
		
		string k = to_string(a);
		int flag = 1;
		if (k.find("666") != -1){
			arr[cnt] = a;
			cnt++;
		}

		a++;
	}
	cout << arr[n - 1];
}
