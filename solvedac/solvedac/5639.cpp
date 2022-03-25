#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node {
	int left;
	int right;
};
node arr[1000001];
int n;

void make_tree(int now, int tree) {
	if (tree > now) {
		if (arr[tree].left == 0) {
			arr[tree].left = now;
		}
		else {
			make_tree(now, arr[tree].left);
		}
	}
	else if (tree < now) {
		if (arr[tree].right == 0) {
			arr[tree].right = now;
		}
		else {
			make_tree(now, arr[tree].right);
		}
	}
}

void print_tree(int node) {
	if (arr[node].left != 0) {
		print_tree(arr[node].left);
	}

	if (arr[node].right != 0) {
		print_tree(arr[node].right);
	}

	cout << node << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int num;
	while (cin>>num) {
		make_tree(num, n);

	}

	print_tree(n);

}