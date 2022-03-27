#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int map[100001][3];
struct node {
	int a0;
	int a1;
	int a2;
};



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	queue<node> q1;
	q1.push({ map[0][0], map[0][1],map[0][2] });
	
	for (int i = 1; i < n;i++) {
		node now = q1.front();
		q1.pop();
		int a, b, c;
		a = max(now.a0 + map[i][0], now.a1 + map[i][0]);
		b = max(max(now.a0 + map[i][1], now.a1 + map[i][1]), now.a2 + map[i][1]);
		c = max(now.a1 + map[i][2], now.a2 + map[i][2]);

		q1.push({ a,b,c });
	}

	queue<node> q2;
	q2.push({ map[0][0], map[0][1],map[0][2] });

	for (int i = 1; i < n; i++) {
		node now = q2.front();
		q2.pop();
		int a, b, c;

		a = min(now.a0 + map[i][0], now.a1 + map[i][0]);
		b = min(min(now.a0 + map[i][1], now.a1 + map[i][1]), now.a2 + map[i][1]);
		c = min(now.a1 + map[i][2], now.a2 + map[i][2]);

		q2.push({ a,b,c });
	}

	node maxv = q1.front();
	node minv = q2.front();

	cout << max(max(maxv.a0, maxv.a1), maxv.a2) << " " << min(min(minv.a0, minv.a1), minv.a2) << endl;
}