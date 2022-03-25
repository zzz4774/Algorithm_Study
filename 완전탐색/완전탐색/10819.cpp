#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;
vector<int> flag;
vector<int> str;
int sum;
int smax;

void dfs(int lv) {
	if (lv == n) {
		for (int i = 0; i < n - 1; i++) {
			sum += abs(str[i] - str[i + 1]);
		}
		if (sum > smax)smax = sum;
		sum = 0;
	}

	for (int i = 0; i < n; i++) {
		if (flag[i] == 0) {
			flag[i] = 1;

			str.push_back(arr[i]);
			dfs(lv + 1);
			str.pop_back();
			flag[i] = 0;
		}
	}
}


int main() {
	cin >> n;


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
		flag.push_back(0);
	}

	dfs(0);

	cout << smax;
}