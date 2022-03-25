#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int ans;
int n, r, c;


void func(int y, int x, int size)
{
    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x) {
        func(y, x, size / 2);
        func(y, x + size / 2, size / 2);
        func(y + size / 2, x, size / 2);
        func(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    func(0, 0, (1 << n));

}