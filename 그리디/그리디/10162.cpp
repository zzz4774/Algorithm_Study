#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	s1 = t / 300;
	t = t % 300;

	s2 = t / 60;
	t = t % 60;

	s3  = t / 10;
	t = t % 10;

	if (t != 0)cout << -1 << endl;
	else {
		cout << s1 << " " << s2 << " " << s3 << endl;
	}
}