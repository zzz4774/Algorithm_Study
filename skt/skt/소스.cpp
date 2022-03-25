#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    vector<vector<int>> tree;
    int count;
    int lv;
};
vector < vector<vector<int>>>used;
vector <int>visit;

int solution(vector<vector<int>> a, vector<vector<int>> b, int m) {
    int answer = 0;

    int  n = a.size() + 1;
    for (int i = 0; i < a.size(); i++) {
        sort(a[i].begin(), a[i].end());
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < b.size(); i++) {
        sort(b[i].begin(), b[i].end());
    }
    sort(b.begin(), b.end());



    queue<node> q;
    q.push({ b, m, 0 });
    int res = -1;


    while (!q.empty()) {
        node now = q.front();
        vector<vector<int>> nb = now.tree;
        q.pop();


        int flag = 1;
        for (int i = 0; i < used.size(); i++) {
            if (nb == used[i] && now.count == visit[i]) {
                flag = 0;
                break;
            }
        }
        if (!flag)continue;


        if (nb == a) {
            if (res < now.count) {
                res = now.count;
            }
        }


        for (int i = 0; i < nb.size(); i++) {
            for (int j = 1; j <= n; j++) {
                if (j != nb[i][0] && j != nb[i][1]) {


                    nb[i] = { nb[i][0], j };

                    for (int i = 0; i < nb.size(); i++) {
                        sort(nb[i].begin(), nb[i].end());
                    }
                    sort(nb.begin(), nb.end());

                    q.push({ nb, now.count, now.lv + 1 });



                    nb[i] = { j, nb[i][1] };
                    for (int i = 0; i < nb.size(); i++) {
                        sort(nb[i].begin(), nb[i].end());
                    }
                    sort(nb.begin(), nb.end());

                    q.push({ nb, now.count, now.lv + 1 });

                }
            }
        }

    }

    return answer;
}



int main() {
    vector<vector<int>> a;
    vector<vector<int>> b;

    a.push_back({ 1,2 });
    a.push_back({ 3,1 });
    a.push_back({ 2,4 });
    a.push_back({ 3,5 });

    b.push_back({ 2,1 });
    b.push_back({ 4,1 });
    b.push_back({ 2,5 });
    b.push_back({ 3,2 });
    int m = 1;

    int res = solution(a, b, m);

}