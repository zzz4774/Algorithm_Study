#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct node {
	int val;
	string path;
};

int fund(int num) {
	int res;
	res = num * 2;
	if (res > 9999) {
		return res % 10000;
	}
	return res;
}
bool visited[10000];

int funs(int num) {
	if (num == 0)return 9999;
	else return num - 1;
}

int funl(int num) {
	return (num % 1000)*10 + num / 1000;
}

int funr(int num) {
	return num / 10 + (num % 10) * 1000;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int start, end;
		cin >> start >> end;
		queue<node> q;
		int index = 0;
		string res;

		q.push({ start, "" });
		visited[start] = true;
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			if (now.val == end) {
				res = now.path;
				break;
			}

			int a1 = fund(now.val);
			if (!visited[a1]) {
				q.push({ a1, now.path + "D" });
				visited[a1] = true;
			}

			int a2 = funs(now.val);
			if (!visited[a2]) {
				q.push({ a2, now.path + "S" });
				visited[a2] = true;
			}
			

			int a3 = funl(now.val);
			if (!visited[a3]) {
				q.push({ a3, now.path + "L" });
				visited[a3] = true;
			}

			int a4 = funr(now.val);
			if (!visited[a4]) {
				q.push({ a4, now.path + "R" });
				visited[a4] = true;
			}

		}

		cout << res << "\n";
		for (int i = 0; i < 10000; i++) {
			visited[i] = false;
		}
	}


}