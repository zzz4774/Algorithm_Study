#include<iostream>
#include<algorithm>
using namespace std;

long long a, b;
int result;
int flag = 0;

void dfs(int x, int cnt) {
	if (x == b) {
		flag = 1;
		result = cnt;
		return;
	}
	else if (x > b) {

		return;
	}
	else {

		dfs(x * 2, cnt + 1);

		dfs(x * 10 + 1, cnt + 1);
	}
}



int main() {
	cin >> a >> b;
	dfs(a, 1);

	if (flag)cout << result;
	else cout << -1;
}





//#include<iostream>
//using namespace std;
//
//long long a, b;
//int cnt = 0;
//
//int main()
//{
//	cin >> a >> b;
//	int flag = 1;
//	while (1) {
//		if (b < a) {
//			flag = 0;
//			break;
//		}
//		else if (b == a) {
//			cnt++;
//			break;
//		}
//		else {
//			if (b % 2 == 0) {
//				b = b / 2;
//				cnt++;
//			}
//			else if ((b - 1) % 10 == 0) {
//				b = (b - 1) / 10;
//				cnt++;
//			}
//			else {
//				flag = 0;
//				break;
//			}
//		}
//
//	}
//	if (flag)cout << cnt;
//	else cout << -1;
//}