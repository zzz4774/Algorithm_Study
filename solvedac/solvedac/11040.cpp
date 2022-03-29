#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;
int vertex, edge;
ll arr[101][101];


void floyd_warshall() {
    for (int i = 1; i <= vertex; i++)
        for (int j = 1; j <= vertex; j++) 
            for (int k = 1; k <= vertex; k++)
                if (arr[j][i] != 2134567890 && arr[i][k] != 2134567890)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}

int main() {
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = 2134567890;
        }
    }

    int from, to, weight;
    for (int i = 0; i < edge; i++) { 
        cin >> from >> to >> weight;
        if (arr[from][to] > weight)
            arr[from][to] = weight;
    }

    floyd_warshall();


    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if (i == j || arr[i][j] == 2134567890) cout << 0 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


}
