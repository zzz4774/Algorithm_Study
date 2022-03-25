#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int>s;
	long long sum = 0;

	int n;
	cin >> n;

	while (n--) {
		int num;
		cin >> num;

		if (num == 0)s.pop();
		else {
			s.push(num);
		}
	}

	while (!s.empty()) {
		int find = s.top();
		s.pop();
		sum += find;
	}

	cout << sum<< endl;
}