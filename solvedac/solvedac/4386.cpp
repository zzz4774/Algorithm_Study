#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

vector<int>parent;

struct node {
	float x;
	float y;
};

struct mst {
	int from;
	int to;
	float dis;
};

bool compare(mst a, mst b) {
	return a.dis < b.dis;
}

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}

void unionf(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pb] = pa;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<node> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].y >> vec[i].x;
	}

	vector<mst> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			v.push_back({ i, j, sqrt(((vec[i].x - vec[j].x) * (vec[i].x - vec[j].x)) + ((vec[i].y - vec[j].y) * (vec[i].y - vec[j].y))) });
		}
	}

	parent = vector<int>(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	float sum = 0;
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		mst now = v[i];

		if (find(now.from) == find(now.to))continue;
		unionf(now.from, now.to);
		sum += now.dis;
	}

	cout<<fixed;
	cout.precision(2);
	cout << sum << endl;
}

