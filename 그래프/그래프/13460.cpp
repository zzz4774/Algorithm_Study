#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct node {
    int rx, ry, bx, by, cnt;
};

node start;
string map[11];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int bfs() {
    int visit[10][10][10][10] = { 0 };
    queue<node> q;
    q.push(start);
    visit[start.rx][start.ry][start.bx][start.by] = 1;

    int ret = -1;
    while (!q.empty()) {
        node now = q.front();   q.pop();

        if (now.cnt > 10)break; 
        if (map[now.rx][now.ry] == 'O' && map[now.bx][now.by] != 'O') { 
            ret = now.cnt;
            break;
        }


        for (int i = 0; i < 4; i++) {
            int next_rx = now.rx;
            int next_ry = now.ry;
            int next_bx = now.bx;
            int next_by = now.by;


            while (1) {
                if (map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O') {
                    next_rx += dx[i]; next_ry += dy[i];
                }
                else {
                    if (map[next_rx][next_ry] == '#') {
                        next_rx -= dx[i]; next_ry -= dy[i];
                    }
                    break;
                }
            }


            while (1) {
                if (map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O') {
                    next_bx += dx[i]; next_by += dy[i];
                }
                else {
                    if (map[next_bx][next_by] == '#') {
                        next_bx -= dx[i]; next_by -= dy[i];
                    }
                    break;
                }
            }

            if (next_rx == next_bx && next_ry == next_by) {
                if (map[next_rx][next_ry] != 'O') {
                    int red_dist = abs(next_ry - now.ry) + abs(next_rx - now.rx);
                    int blue_dist = abs(next_by - now.by) + abs(next_bx - now.bx);

                    if (red_dist > blue_dist) {
                        next_rx -= dx[i]; next_ry -= dy[i];
                    }
                    else {
                        next_bx -= dx[i]; next_by -= dy[i];
                    }
                }
            }

            if (visit[next_rx][next_ry][next_bx][next_by] == 0) {
                visit[next_rx][next_ry][next_bx][next_by] = 1;
                node next;
                next.rx = next_rx;
                next.ry = next_ry;
                next.bx = next_bx;
                next.by = next_by;
                next.cnt = now.cnt + 1;
                q.push(next);
            }


        }
    }

    return ret;
}
int main() {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
            }
            if (map[i][j] == 'B') {
                start.bx = i;
                start.by = j;
            }
        }
    }
    start.cnt = 0;
    int ans = bfs();
    cout << ans;

    return 0;
}