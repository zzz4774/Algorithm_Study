#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int arr[2000000];

int find(int now) {
	if (arr[now] == now)return now;
	return arr[now] = find(arr[now]);
}

void unionf(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	arr[pb] = pa;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	int a, b, k;
	while (m--) {
		cin >> k >> a >> b;
		if (k == 0) {
			unionf(a, b);
		}
		else if (k == 1) {
			if (find(a) != find(b)) {
				cout << "NO\n";
			}
			else cout << "YES\n";
		}
	}


}