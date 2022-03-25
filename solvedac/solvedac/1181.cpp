#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str[20001];
bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str + n, compare);
	


	for (int i = 0; i < n; i++) {
		if (str[i] != str[i + 1])cout << str[i] << endl;;
	}

	

}