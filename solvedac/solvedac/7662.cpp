#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		char order;
		int num;
		multiset <int> ms;
		while (n--) {
			cin >> order >> num;
			if (order == 'I') {
				ms.insert(num);
			}
			else {
				if (!ms.empty()) {
					if (num == -1) {
						ms.erase(ms.begin());
					}
					else if (num == 1) {
						auto iter = ms.end();
						iter--;
						ms.erase(iter);
					}
				}
			}

		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto iter = ms.end();
			iter--;
			cout << *iter << " " << *ms.begin() << "\n";
		}
	}

}