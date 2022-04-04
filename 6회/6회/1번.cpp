#include<iostream>
#include<string>
using namespace std;

int isValid(string tar) {
	if (tar.length() != 5)return 0;
	for (int i = 0; i < 5; i++) {
		if (!(tar[i] >= '0' && tar[i] <= '9'))return 0;
	}
	return 1;
}

void go(string str) {
	int a = 0;
	int b;

	while (1) {
		a = str.find('[', a);
		if (a == -1)return;

		b = str.find(']', a + 1);
		if (b == -1)return;

		string temp = str.substr(a + 1, b - a - 1);
		if (isValid(temp) == 1) {
			cout << "[" << temp << "]\n";
		}

		a = b + 1;
	}
}

int main() {
	go("OK[00700]HI[30431][12345]");
	return 0;
}