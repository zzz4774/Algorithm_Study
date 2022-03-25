#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct num {
	int value;
	int mark;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int p;
	cin >> p;
	while (p--) {
		int n, m;
		cin >> n >> m;
		queue<num> q;
		int cnt = 0;
		int dat[10] = {0};


		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (i == m)q.push({ tmp, 1 });
			else q.push({ tmp, 0 });
			
			dat[tmp] += 1;
		}


		
		while (!q.empty()) {
			num now = q.front();
			q.pop();

			int flag = 0;
			for (int i = now.value + 1; i <= 9; i++) {
				if (dat[i] != 0)flag = 1;
			}
			if (flag) {
				q.push(now);
			}
			else {
				cnt++;
				dat[now.value]--;
				if (now.mark == 1) {
					cout << cnt << "\n";
					break;
				}
			}
		}

	}
}