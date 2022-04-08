#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int arr[1000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;

	int day = 0;
	for (int i = 1; i < x; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)day += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)day += 30;
		else day += 28;
	}

	day += y - 1;

	if (day % 7 == 0)cout << "MON" << endl;
	else if (day % 7 == 1)cout << "TUE" << endl;
	else if (day % 7 == 2)cout << "WED" << endl;
	else if (day % 7 == 3)cout << "THU" << endl;
	else if (day % 7 == 4)cout << "FRI" << endl;
	else if (day % 7 == 5)cout << "SAT" << endl;
	else if (day % 7 == 6)cout << "SUN" << endl;
}