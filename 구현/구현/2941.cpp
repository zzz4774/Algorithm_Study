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


	string str;
	cin >> str;
	int sum = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'c' && str[i+1] == '=') {
			sum++;
			i = i + 1;
		}
		else if (str[i] == 'c' && str[i+1] == '-') {
			sum++;
			i = i + 1;
		}
		else if (i<str.size() - 2 && str[i] == 'd' && str[i + 1] == 'z' && str[i+2] == '=') {
			sum++;
			i = i + 2;
		}
		else if (str[i] == 'd' && str[i + 1] == '-') {
			sum++;
			i = i + 1;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j') {
			sum++;
			i = i + 1;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j') {
			sum++;
			i = i + 1;
		}
		else if (str[i] == 's' && str[i + 1] == '=') {
			sum++;
			i = i + 1;
		}
		else if (str[i] == 'z' && str[i + 1] == '=') {
			sum++;
			i = i + 1;
		}
		else sum++;
	}





	cout << sum << endl;
}