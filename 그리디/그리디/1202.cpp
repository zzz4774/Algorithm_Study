#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct node {
	int w;
	int v;
};

bool compare(node a, node b) {
	return a.w < b.w;
}

priority_queue<int> pq;
vector<int> bag;
vector<node> v;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		bag.push_back(num);
	}

	ll sum = 0;
	sort(bag.begin(), bag.end());
	sort(v.begin(), v.end(), compare);

	int index = 0;
	for (int i = 0; i < k; i++) {
		int now = bag[i];
		while (index < n && v[index].w <= now) {
			pq.push(v[index].v);
			index++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}




	cout << sum << endl;


}