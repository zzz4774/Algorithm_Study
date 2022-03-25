#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	queue <int>q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int now;
	while (1) {
		now = q.front();
		q.pop();
		if (q.empty())break;

		now = q.front();
		q.pop();
		if (q.empty())break;
		q.push(now);
	}

	cout << now << endl;
}