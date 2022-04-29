#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int MOD = 1000000;
int P = 1500000;

int fibo[1500000] = { 0, 1 };

int main() {
    long long n;
    cin >> n;

    for (int i = 2; i < P; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }

    cout << fibo[n % P] << "\n";
    return 0;
}