#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
int used[100000];
struct where {
	int num;
	int cnt;
};
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	queue <where> q;
	q.push({ n, 0 });
	used[n] = 1;
	
	while (!q.empty()) {
		where now = q.front();
		q.pop();
		if (now.num == k) {
			cout << now.cnt << "\n";
			break;
		}

		if (now.num + 1 <= 100000 && used[now.num + 1] == 0) {
			used[now.num + 1] = 1;
			q.push({ now.num + 1, now.cnt + 1 });
		}
		if (now.num - 1 <= 100000 && used[now.num - 1] == 0) {
			used[now.num - 1] = 1;
			q.push({ now.num - 1, now.cnt + 1 });
		}
		if (now.num * 2 <= 100000 && used[now.num * 2] == 0) {
			used[now.num * 2] = 1;
			q.push({ now.num * 2, now.cnt + 1 });
		}
	}
	

}