#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int map[50][50];
int p[50];
int used[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int truenum;

	cin >> n >> m;
	cin >> truenum;
	for (int i = 0; i < truenum; i++) {
		int num;
		cin >> num;
		used[num] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> p[i];
		for (int j = 0; j < p[i]; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		int mflag = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p[i]; j++) {
				if (used[map[i][j]] == 1) {
					for (int s = 0; s < p[i]; s++) {
						if (used[map[i][s]] == 0) {
							used[map[i][s]] = 1;
							mflag = 0;
						}
					}
					break;
				}
				
			}
		}

		if (mflag)break;
	}
	
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int flag = 1;

		for (int j = 0; j < p[i]; j++) {
			if (used[map[i][j]] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag)cnt++;
	}

	cout << cnt << endl;

}