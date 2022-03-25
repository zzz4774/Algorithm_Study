#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int call0;
int call1;

struct num {
    int case0;
    int case1;
};
num arr[41];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    arr[0].case0 = 1;
    arr[0].case1 = 0;

    arr[1].case0 = 0;
    arr[1].case1 = 1;


    for (int i = 2; i <= 40; i++) {
        arr[i].case0 = arr[i - 1].case0 + arr[i - 2].case0;
        arr[i].case1 = arr[i - 1].case1 + arr[i - 2].case1;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << arr[n].case0 << " " << arr[n].case1 << "\n";
    }

}