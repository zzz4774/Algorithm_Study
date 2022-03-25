#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct dep {
	int kg;
	int cm;
};
dep arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].kg >> arr[i].cm;
	}

	int rank = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].kg < arr[j].kg && arr[i].cm < arr[j].cm) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}

	return  0;
}