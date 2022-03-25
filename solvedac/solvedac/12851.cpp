#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
struct node {
	int num;
	int lv;
};
int cnt;
int val = 2134567890;
int used[100000];
int n, k;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	queue<node> q;
	vector<int>used(100001, 21345678);

	if (n == k) {
		cout << 0 << endl << 1 << endl;
	}
	else {
		q.push({ n,0 });

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			if (now.lv > val)continue;
			if (used[now.num] < now.lv)continue;
			used[now.num] = now.lv;

			if (now.num == k) {
				val = now.lv;
				cnt++;
			}
			if (now.num + 1 >= 0 && now.num + 1 <= 100000) {
				q.push({ now.num + 1, now.lv + 1 });
			}
			if (now.num - 1 >= 0 && now.num - 1 <= 100000) {
				q.push({ now.num - 1, now.lv + 1 });
			}
			if (now.num * 2 >= 0 && now.num * 2 <= 100000) {
				q.push({ now.num * 2, now.lv + 1 });
			}

			
		}

		cout << val << endl << cnt << endl;
	}

	
	

}