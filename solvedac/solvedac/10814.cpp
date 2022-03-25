#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct boj {
	int age;
	string name;
};

bool compare(boj a, boj b) {
	return a.age < b.age;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<boj> v;
	for (int i = 0; i < n; i++) {
		int x;
		string y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
}