#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct node {
	string s;
	int cnt;
};

bool compare(string a, string b) {
	return a< b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<node> v;
	vector<string> st;
	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		int a = str.find(".");
		string tmp = str.substr(a + 1, str.size() - a);

		st.push_back(tmp);
	}



	sort(st.begin(), st.end(), compare);


	string t = st[0];
	int cnt = 0;
	for (int i = 0; i < st.size(); i++) {
		if (t == st[i])cnt++;
		else if (t != st[i]) {
			v.push_back({ t, cnt });
			cnt = 1;
			t = st[i];



		}
		
		if (i == st.size() - 1) {
			v.push_back({ t, cnt });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].s << " " << v[i].cnt << "\n";
	}

}