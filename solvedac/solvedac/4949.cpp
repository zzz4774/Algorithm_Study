#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 0;
	while (1) {
		string c;
		getline(cin, c);
		int x = c.size();
		
		if (c == ".")break;

		int flag = 1;
		for (int i = 0; i < x; i++) {
			if (c[i] == '(') {
				int can = 0;
				int wait = 0;
				for (int j = i + 1; j < x; j++) {
					if (c[j] == '[') {
						can++;
					}
					if (c[j] == '(') {
						wait++;
					}
					if (c[j] == ')' && wait != 0) {
						wait--;
					}
					else if (c[j] == ')' &&can==0 &&wait==0) {
						c[i] = ' ';
						c[j] = ' ';
						break;
					}
					else if (c[j] == ')' && can != 0 && wait==0) {
						flag = 0;
						break;
					}
					
					if (c[j] == ']' && can>0){
						can--;
					}
					else if (c[j] == ']' && can == 0) {
						flag = 0;
						break;
					}
				}
			}

			if (c[i] == '[') {
				int wait = 0;
				int can = 0;
				for (int j = i + 1; j < x; j++) {
					if (c[j] == '(') {
						can++;
					}
					if (c[j] == '[') {
						wait++;
					}
					if (c[j] == ']' && wait != 0) {
						wait--;
					}
					else if (c[j] == ']' && can == 0 && wait == 0) {
						c[i] = ' ';
						c[j] = ' ';
						break;
					}
					else if (c[j] == ']' && can != 0 && wait == 0) {
						flag = 0;
						break;
					}

					if (c[j] == ')' && can > 0) {
						can--;
					}
					else if (c[j] == ')' && can == 0) {
						flag = 0;
						break;
					}
				}
			}
			if (!flag)break;
		}

		if (flag) {
			for (int i = 0; i < x; i++) {
				if (c[i] == ']' || c[i] == '[' || c[i] == ')' || c[i] == '(') {
					flag = 0;
					break;
				}
			}
		}


		if (!flag)cout << "no\n";
		else cout << "yes\n";
		
	}
}