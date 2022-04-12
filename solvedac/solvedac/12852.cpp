#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int x;
	int cnt;
	vector<int>path;
};
node dp[1000001];
int visited[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	queue<node> q;
	q.push({ n, 0, {n} });

	while (!q.empty()) {
		node now = q.front();
		
		q.pop();

		if (visited[now.x] == 1)continue;
		visited[now.x] = 1;
		
		if (now.x == 1) {
			cout << now.cnt << endl;
			for (int i = 0; i <= now.cnt; i++) {
				cout << now.path[i] << " ";
			}
			return 0;
		}

		if (now.x % 3 == 0) {
			now.path.push_back(now.x / 3);
			q.push({ (now.x / 3), (now.cnt + 1), now.path });
			now.path.pop_back();
		}

		if (now.x % 2 == 0) {
			now.path.push_back(now.x / 2);
			q.push({ (now.x / 2), (now.cnt + 1), now.path });
			now.path.pop_back();
		}

		now.path.push_back(now.x - 1);
		q.push({ (now.x - 1), (now.cnt + 1), now.path });
		now.path.pop_back();
	}

}