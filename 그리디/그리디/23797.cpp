#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	int Kcnt = 0;
	int Pcnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'K' && Pcnt == 0) {
			Kcnt++;
		}
		else if (str[i] == 'K' && Pcnt != 0) {
			Kcnt++;
			Pcnt--;
		}

		if (str[i] == 'P' && Kcnt == 0) {
			Pcnt++;
		}
		else if (str[i] == 'P' && Kcnt != 0) {
			Pcnt++;
			Kcnt--;
		}

	
	}
	cout << Kcnt + Pcnt << endl;

}