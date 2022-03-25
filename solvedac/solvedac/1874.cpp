#include<iostream>
#include<string>
#include<stack>
using namespace std;

int arr[100000];
char str[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int flag = 1;
	int cnt = 0;
	int num = 1;
	s.push(num);
	str[cnt] = '+';
	cnt++;
	num++;
	for (int i = 0; i < n; i++) {
		while (1) {

			if (num <= arr[i] && s.empty()) {
				s.push(num);
				str[cnt] = '+';
				cnt++;
				num++;
			}
			else if (num > arr[i] && s.empty()) {
				flag = 0;
				break;
			}
			else if (arr[i] > s.top()) {
				s.push(num);
				str[cnt] = '+';
				cnt++;
				num++;
			}
			else if (arr[i] < s.top()) {
				s.pop();
				str[cnt] = '-';
				cnt++;
			}
			else if (arr[i] == s.top()) {
				s.pop();
				str[cnt] = '-';
				cnt++;
				break;
			}
		}
	}

	if (flag) {
		for (int i = 0; i < cnt; i++) {
			cout << str[i] << "\n";
		}
	}
	else cout << "NO";


}