#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node {
	string addr;
	string pass;

};
int n, m;
node arr[100000];
string wh[100000];


void bs(string now) {
	int start = 0;
	int end = n - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid].addr > now)end = mid - 1;
		else if (arr[mid].addr < now)start = mid + 1;
		else if (arr[mid].addr == now) {
			cout << arr[mid].pass << "\n";
			break;
		}
	}
}

bool compare(node a, node b) {
	return a.addr < b.addr;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].addr >> arr[i].pass;
	}
	for (int i = 0; i < m; i++) {
		cin >> wh[i];
	}

	sort(arr, arr + n, compare);
	for (int i = 0; i < m; i++) {
		bs(wh[i]);
	}
}