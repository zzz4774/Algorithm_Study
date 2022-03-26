#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;


vector <string>v;

bool compare(string a, string b) {
	int aLen = a.length();
	int bLen = b.length();
	if (aLen > bLen)
		return false;
	else if (aLen < bLen)
		return true;
	else
		return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;

		
		string tmp = "";

		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				tmp += str[i];
			}
			else if (tmp != "") {
				while (true) {
					if (tmp.length() > 1 && tmp.at(0) == '0') tmp = tmp.substr(1, tmp.length() - 1);
					else break;
				}

				v.push_back(tmp);
				tmp = "";
			}

			if (i == str.size() - 1 && tmp != "") {

				while (true) {
					if (tmp.length() > 1 && tmp.at(0) == '0') tmp = tmp.substr(1, tmp.length() - 1);
					else break;
				}


				v.push_back(tmp);
				tmp = "";
			}
		}
		
		tmp = "";
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

}