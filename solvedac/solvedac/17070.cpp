#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node {
	int a1;
	int a2;
	int a3;
	int block;
};

node map[20][20];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j].block;
		}
	}

	map[1][2].a1 = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].block == 1)continue;

		
			map[i][j].a3 += map[i - 1][j].a3;
			map[i][j].a3 += map[i - 1][j].a2;

			map[i][j].a1 += map[i][j - 1].a2;
			map[i][j].a1 += map[i][j - 1].a1;


			if (map[i][j - 1].block == 0 && map[i - 1][j].block == 0) {

				map[i][j].a2 += map[i - 1][j - 1].a1;
				map[i][j].a2 += map[i - 1][j - 1].a2;
				map[i][j].a2 += map[i - 1][j - 1].a3;
			}
			
		}
	}

	cout << map[n][n].a1 + map[n][n].a2 + map[n][n].a3 << endl;
}