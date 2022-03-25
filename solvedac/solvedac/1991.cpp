#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
struct node {
	char root;
	char left;
	char right;
};
node arr[30];

void front(node now) {
	cout << now.root;
	if (now.left != '.') {
		front(arr[now.left - 'A']);
	}

	if (now.right != '.') {
		front(arr[now.right- 'A']);
	}
}

void mid(node now) {
	if (now.left != '.') {
		mid(arr[now.left - 'A']);
	}

	cout << now.root;
	

	if (now.right != '.') {
		mid(arr[now.right - 'A']);
	}
}

void back(node now) {
	if (now.left != '.') {
		back(arr[now.left - 'A']);
	}

	if (now.right != '.') {
		back(arr[now.right - 'A']);
	}
	cout << now.root;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char now;
		cin >> now;
		arr[now - 'A'].root = now;
		cin >> arr[now - 'A'].left >> arr[now - 'A'].right;
	}

	front(arr[0]);
	cout << endl;
	mid(arr[0]);
	cout << endl;
	back(arr[0]);
	cout << endl;

}