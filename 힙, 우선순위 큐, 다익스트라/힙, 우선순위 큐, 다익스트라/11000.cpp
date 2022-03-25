#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct node {
	int start;
	int end;
};
priority_queue<int, vector<int>, greater<int>> pq;
node arr[200001];

bool compare(node a, node b) {
	if (a.start == b.start)return a.end < b.end;
	return a.start < b.start;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + n, compare);
	pq.push(arr[0].end);

	for (int i = 1; i < n; i++) {
		if (arr[i].start >= pq.top()) {
			pq.pop();
			pq.push(arr[i].end);
		}
		else {
			pq.push(arr[i].end);
		}
	}

	cout << pq.size() << endl;
	
}