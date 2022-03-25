#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> q;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		q.push(i);
	}

	cout << "<";
	
	while (1) {
		int num = b - 1;
		while (num--) {
			int k = q.front();
			q.pop();
			q.push(k);
		}

		int k = q.front();
		cout << k;
		q.pop();
		if (q.empty())break;
		cout << ", ";
	}
	cout << ">" << endl;
}