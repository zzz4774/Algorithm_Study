#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct lay {
	int y;
	int x;
};
lay arr[100001];

bool compare(lay a, lay b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

}