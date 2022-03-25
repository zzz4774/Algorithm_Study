#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > mpq;
priority_queue<int, vector<int>, greater<int> > npq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int num = 1;
	while (n--) {
		int a;
		cin >> a;
		if (mpq.size() == npq.size()) {
			mpq.push(a);
		}
		else npq.push(a);

		if (!mpq.empty() && !npq.empty() && mpq.top() > npq.top()) {
			int max, min;
			max = mpq.top();
			min = npq.top();
			mpq.pop();
			npq.pop();
			mpq.push(min);
			npq.push(max);
		}
		cout << mpq.top() << "\n";
	}
}