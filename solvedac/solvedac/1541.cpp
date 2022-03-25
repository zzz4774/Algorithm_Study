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
	int result = 0;
	string tmp = "";
	int flag = 0;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i]=='\0') {
			if (str[i] == '-' && flag == 0) {
				result += stoi(tmp);
				flag = 1;
			}
			else if (flag) {
				result -= stoi(tmp);
			}
			else if (!flag) {
				result += stoi(tmp);
			}
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	cout << result << endl;
}