#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int score[200000];
int study[200000];
struct node {
	int sc;
	int st;
};
priority_queue<node>pq;
bool operator<(node a, node b) {
	if (a.st == b.st)return a.sc > b.sc;
	else return a.st < b.st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> score[i];
		sum += score[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> study[i];
		pq.push({ 100 - score[i], study[i] });
	}

	
	int hour = n * 24;
	while (hour > 0 && !pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.sc >= now.st) {
			sum += now.st;
			pq.push({ now.sc - now.st, now.st });
			hour--;
		}
		else {
			pq.push({ now.sc ,now.sc });
		}
		
	}
	cout << sum << endl;
	return 0;


}