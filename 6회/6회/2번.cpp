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
		cout << "M�� �����մϴ�\n";
	}
	else {
		cout << "M�� �������� �ʽ��ϴ�.\n";
	}

	return 0;
}