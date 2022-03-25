#include<iostream>
#include<algorithm>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node {
	ll start;
	ll end;
};

node arr[100000];
bool compare(node a, node b) {
	if (a.end == b.end)return a.start < b.start;
	return a.end < b.end;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node a;
		cin >> a.start >> a.end;
		arr[i] = a;
	}

	sort(arr, arr + n, compare);

	ll now;
	int f = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (f <= arr[i].start) {
			f = arr[i].end;
			cnt++;
		}

	}
	cout << cnt << endl;

}