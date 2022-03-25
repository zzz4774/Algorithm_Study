#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int sum = 0;
	while (pq.size() != 1) {
		int x = pq.top();
		sum += x;
		pq.pop();
		int y = pq.top();
		sum += y;
		pq.pop();
		pq.push(x + y);
	}
	cout << sum;

}