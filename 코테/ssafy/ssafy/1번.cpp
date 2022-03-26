#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int gate[3];
int num[3];
int fish[61];
int n;

int check1(int start, int num) {
	int res = 0;

	for (int i = 0; i < num; i++) {
		int k = 0;
		while (1) {
			int flag = 0;
			if (fish[start + k] == 0 && start + k >= 1 && start + k <= n) {
				fish[start + k] = 1;
				res += k + 1;
				flag = 1;
			}

			if (flag)break;
			else if (fish[start - k] == 0 && start - k >= 1 && start - k <= n) {
				fish[start - k] = 1;
				res += k + 1;
				flag = 1;
			}

			if (flag)break;
			else {
				k++;
			}
		}
	}

	return res;
}

int check2(int start, int num) {
	int res = 0;

	for (int i = 0; i < num; i++) {
		int k = 0;
		while (1) {
			int flag = 0;
			if (fish[start - k] == 0 && start - k >= 1 && start - k <= n) {
				fish[start - k] = 1;
				res += k + 1;
				flag = 1;
			}

			if (flag)break;
			else if (fish[start + k] == 0 && start + k >= 1 && start + k <= n) {
				fish[start + k] = 1;
				res += k + 1;
				flag = 1;
			}

			if (flag)break;
			else {
				k++;
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for(int pp=1;pp<=t;pp++){
		cin >> n;
		for (int i = 0; i < 3; i++) {
			cin >> gate[i] >> num[i];
		}
		int min = 21345670;
		int sum = 0;

		sum += check1(gate[0], num[0]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;

		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}

		sum += check2(gate[0], num[0]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;

		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}







		sum += check1(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}





		sum += check1(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check1(gate[2], num[2]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check2(gate[2], num[2]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		




		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		sum += check1(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		sum += check2(gate[2], num[2]);
		if (min > sum)min = sum;
		sum = 0;

		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}



		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;

		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}



		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check1(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check1(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check1(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}
		sum += check2(gate[2], num[2]);
		sum += check2(gate[1], num[1]);
		sum += check2(gate[0], num[0]);
		if (min > sum)min = sum;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fish[i] = 0;
		}


		cout <<"#"<<pp<<" " << min << "\n";

	}
}

