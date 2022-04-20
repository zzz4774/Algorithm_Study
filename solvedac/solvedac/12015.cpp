#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int arr[1000001];
vector<int> res;
int n;

void binary_search(int num) {
    int low = 0, high = res.size() - 1, mid;
    int ret = 1000000007;
    while (low <= high) {
        mid = (low + high) / 2;
        int now = res[mid];
        if (now >= num) {
            if (ret > mid)
                ret = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    res[ret] = num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    res.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (res.back() < arr[i]) {
            res.push_back(arr[i]);
        }
        else {
            binary_search(arr[i]);
        }
    }

    cout << res.size() << endl;

    return 0;
}
