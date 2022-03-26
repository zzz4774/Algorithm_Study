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
    q.push({ b, 0, 0 });
    int res = 453454;
    

    while (!q.empty()) {
        node now = q.front();
        vector<vector<int>> nb = now.tree;
        q.pop();


        int flag = 1;
        for (int i = 0; i < used.size(); i++) {
            if (nb == used[i]  && now.count == visit[i]) {
                flag = 0;
                break;
            }
        }
        if (!flag)continue;
        used.push_back(nb);
        visit.push_back(now.count);



        if (nb == a) {
            if (res > now.count) {
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

        if (now.count < m) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {

                        for (int k = 0; k < nb.size(); k++) {
                            if ((nb[k][0] == i && nb[k][1] == j) || (nb[k][0] == j && nb[k][1] == i))continue;
                            if (nb[k][0] == i)nb[k][0] = j;
                            else if (nb[k][0] == j)nb[k][0] = i;

                            if (nb[k][1] == i)nb[k][1] = j;
                            else if (nb[k][1] == j)nb[k][1] = i;
                        }


                        for (int i = 0; i < nb.size(); i++) {
                            sort(nb[i].begin(), nb[i].end());
                        }
                        sort(nb.begin(), nb.end());

                        q.push({ nb, now.count + 1, now.lv + 1 });
                        
                    }
                }
            }
        }

    }

    answer = res;

    return answer;
}

