#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int c1 = (r1 - r2) * (r1 - r2);
        int c2 = (r1 + r2) * (r1 + r2);
        if (d == 0)
        {
            if (c1 == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (d == c1 || d == c2)
            cout << "1" << '\n';
        else if (c1 < d && d < c2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
    }
}