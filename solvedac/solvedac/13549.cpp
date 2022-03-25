#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct node {
	int where;
	int time;
};
int used[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int start, end;
	cin >> start >> end;
	queue<node> q;
	q.push({ start,0 });

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (used[now.where] == 1)continue;
		used[now.where] = 1;

		if (now.where == end) {
			cout << now.time << endl;
			return 0;
		}

		int n = now.where * 2;
		while (1) {
			if (n == 0 || n > 100000)break;
			q.push({ n, now.time });
			n = n * 2;
		}

		if (now.where + 1 >= 0 && now.where + 1 <= 100000) {
			q.push({ now.where + 1, now.time + 1 });
		}
		if (now.where -1 >= 0 && now.where - 1 <= 100000) {
			q.push({ now.where - 1, now.time + 1 });
		}


		



	}

	
}