#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int x;
	int y;
};

node arr[100000];
bool compare(node a, node b) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int n;
	cin >> t;
	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].x >> arr[i].y;
		}


		sort(arr, arr + n, compare);
		int num = 0;
		int res = 1;
		for (int i = 1; i < n; i++) {
			if (arr[num].y > arr[i].y) {
				res++;
				num = i;
			}
		}

		cout << res << endl;
	}
}