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

    //�� �˻�
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int f1 = 1;
        for (int j = 0; j + 1 < n; j++) {
            if (map[i][j] == map[i][j + 1]) cnt++; //���̰� ���ٸ� ���ӵ� ���� ���� ��� �� ����
            else if (map[i][j] - map[i][j + 1] == -1)//���̰� ������ ��� 
            {
                if (cnt >= k) //���ݱ����� ���ӵ� ��ܼ��� ���θ� ���� �� ������ �������� ����
                    cnt = 1; // ���� �� �ִٸ� �ٽ� ���ӵ� ��ܼ��� 1
                else f1 = 0; //���� �� ���ٸ� ���� ���� �� ����
            }
            else if (map[i][j] - map[i][j + 1] == 1)//���̰� ������ ���
            {
                if (cnt < 0) f1 = 0; //���� ���̼��� ���� ��,�ʿ䰡 �� ������ �� ���ΰ� �ʿ��ϴ� ���� �Ұ��� ����̹Ƿ� �÷��� ǥ��
                else cnt = -(k - 1); // ������ k-1���� ���� ���̼��� �ʿ��ϹǷ� 
            }
            else f1 = 0;//���� ��ʸ� �����ϸ� ��� �Ұ�
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
