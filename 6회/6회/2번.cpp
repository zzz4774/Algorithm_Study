#include<iostream>
#include<string>
using namespace std;

int isExist(char str[]) {
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		if (str[i] == 'M')return 1;
	}

	return 0;
}

int main() {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		char ch[11];
		cin >> ch;
		if (ret)continue;
		ret = isExist(ch);
	}

	if (ret == 1) {
		cout << "M이 존재합니다\n";
	}
	else {
		cout << "M이 존재하지 않습니다.\n";
	}

	return 0;
}