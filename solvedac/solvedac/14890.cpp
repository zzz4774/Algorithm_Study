#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int n, k, ans = 0, t1 = 0, t2 = 0;
int map[100][100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    //행 검사
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int f1 = 1;
        for (int j = 0; j + 1 < n; j++) {
            if (map[i][j] == map[i][j + 1]) cnt++; //높이가 같다면 연속된 같은 높이 계단 수 증가
            else if (map[i][j] - map[i][j + 1] == -1)//높이가 높아질 경우 
            {
                if (cnt >= k) //지금까지의 연속된 계단수가 경사로를 놓을 수 있을지 없을지를 결정
                    cnt = 1; // 놓을 수 있다면 다시 연속된 계단수는 1
                else f1 = 0; //놓을 수 없다면 길을 만들 수 없다
            }
            else if (map[i][j] - map[i][j + 1] == 1)//높이가 낮아질 경우
            {
                if (cnt < 0) f1 = 0; //같은 높이수가 음수 즉,필요가 더 많은데 또 경사로가 필요하는 경우는 불가한 경우이므로 플레그 표시
                else cnt = -(k - 1); // 앞으로 k-1개의 같은 높이수가 필요하므로 
            }
            else f1 = 0;//위의 사례를 제외하면 모두 불가
        }
        if (cnt >= 0 && f1)t1++;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int f2 = 1;
        for (int j = 0; j + 1 < n; j++) {
            if (map[j][i] == map[j + 1][i]) cnt++;
            else if (map[j][i] - map[j + 1][i] == -1)
            {
                if (cnt >= k) cnt = 1;
                else f2 = 0;
            }
            else if (map[j][i] - map[j + 1][i] == 1)
            {
                if (cnt < 0) f2 = 0;
                else cnt = -(k - 1);
            }
            else f2 = 0;
        }
        if (cnt >= 0 && f2)t2++;

    }
    cout << t1 + t2 << endl;
}
