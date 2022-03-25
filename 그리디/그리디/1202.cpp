#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int w;
	int v;
};
bool operator<(node a, node b) {
	
	return a.v < b.v;
}
priority_queue<node> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}
}