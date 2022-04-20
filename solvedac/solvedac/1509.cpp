#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define MAX 2501

string str = " ";
bool dp[MAX][MAX];
int Result[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string temp;
	cin >> temp;
	str += temp;

	for (int i = 1; i < str.size(); i++)
		dp[i][i] = true;

	for (int i = 1; i < str.size(); i++)
		if (str[i] == str[i + 1])
			dp[i][i + 1] = true;

	for (int i = 2; i < str.size(); i++)
		for (int j = 1; j < str.size() - i; j++)
			if (str[j] == str[j + i] && dp[j + 1][i + j - 1])
				dp[j][j + i] = true;


	Result[0] = 0;
	for (int i = 1; i < str.size(); i++) {
		Result[i] = 10000000;
		for (int j = 1; j <= i; j++)
			if (dp[j][i])
				Result[i] = min(Result[i], Result[j - 1] + 1);
	}
	cout << Result[str.size() - 1] <<endl;
	return 0;
}