#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

double x[10000], y[10000];

double ccw(int a, int b, int c) {
	double aa[2] = { y[b] - y[a],x[b] - x[a] };
	double bb[2] = { y[c] - y[a],x[c] - x[a] };
	return  (aa[0] * bb[1] - aa[1] * bb[0]) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	double result = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i < num - 1; i++)
		result += ccw(0, i, i + 1);

	cout.precision(1);
	cout << fixed;
	cout << abs(result)<<endl;
}