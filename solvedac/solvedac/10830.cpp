#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int map[5][5];
int str[41][5][5];
int arr[41];
int res[5][5];
int tmp[5][5];
int n;
ll m;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			str[0][i][j] = map[i][j];
		}
	}

	for (int i = 40; i >= 0; i--) {
		if (m >= pow(2, i)) {
			arr[i] = 1;
			m -= pow(2, i);
		}
	}

	for (int k = 1; k < 41; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				for (int a = 0; a < n; a++) {
					
						str[k][i][j] += (str[k - 1][i][a] * str[k - 1][a][j] % 1000);
					
				}

				str[k][i][j] %= 1000;
				
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < 41; i++) {
		if (arr[i] == 1) {
			if (flag == 0) {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						res[a][b] = str[i][a][b];
					}
					flag = 1;
				}
			}

			else {
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						tmp[a][b] = res[a][b];
						res[a][b] = 0;
					}
				}



				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						

						for (int r = 0; r < n; r++) {
								res[a][b] += (tmp[a][r] * str[i][r][b] % 1000);
						}

						res[a][b] %= 1000;



					}
				}
			}
		}
	}



	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (res[a][b] == 1000)cout << 0 << " ";
			else cout << res[a][b] << " ";
		}
		cout << "\n";
	}



}