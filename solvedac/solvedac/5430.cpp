#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[110000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int direct = 1;
		int flag = 1;
		string str;
		int num;
		string ar;
		cin >> str >> num >> ar;


			int x = 1;
			int aflag = 1;
			if (num == 0) {
				aflag = 0;
			}
			for (int i = 0; i < num - 1; i++) {
				int end = ar.find(",", x);
				string subs = ar.substr(x, end - x);
				arr[i] = stoi(subs);
				x = end + 1;
			}
			if (aflag) {
				int end = ar.find("]", x);
				string subs = ar.substr(x, end - x);
				arr[num-1] = stoi(subs);
			}

			int start = 0;
			int end = num - 1;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'R') {

					if (direct == 1)direct = 0;
					else direct = 1;

				}
				else if (str[i] == 'D') {
					if (start > end) {
						cout << "error" << "\n";
						flag = 0;
						break;
					}

					if (direct == 1) {
						start += 1;
					}
					else {
						end -= 1;
					}

					
					
				}
			}
		
		
		if (!flag)continue;
		cout << "[";
		if (start <= end) {
			if (direct == 1) {
				for (int i = start; i < end; i++) {
					cout << arr[i] << ",";
				}
				cout << arr[end];
			}
			else {
				for (int i = end; i > start; i--) {
					cout << arr[i] << ",";
				}
				cout << arr[start];
			}
		}
		
		cout << "]" << endl;
	}

}