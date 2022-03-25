#include <string>
#include <vector>
#include<algorithm>
using namespace std;
struct node {
    string command = "";
    int t1 = 0;
    int start = 0;
    int t2 = 0;
    int A = 0;
    int B = 0;
    string C = "";
    int used = 0;
    int wait = 0;
};
int state;
struct pq {
    string str;
    int val;
};

bool compare(pq a, pq b) {
    return a.val < b.val;
}

vector<string> solution(vector<string> arr, vector<string> processes) {
    vector<string> answer;
    
    vector<pq> res;
    int k = processes.size();
    vector<node> v(processes.size());
    for (int i = 0; i < processes.size(); i++) {
        int a1 = 0;
        int a2 = 0;
        int a3 = 0;
        int a4 = 0;
        int a5 = 0;
        int a6 = 0;

        a1 = processes[i].find(" ");
        string tmp = processes[i].substr(0, a1);
        v[i].command = tmp;
        if (v[i].command == "read") {
            a2 = processes[i].find(" ", a1 + 1);
            tmp = processes[i].substr(a1, a2 - a1);
            v[i].t1 = stoi(tmp);

            a3 = processes[i].find(" ", a2 + 1);
            tmp = processes[i].substr(a2, a3 - a2);
            v[i].t2 = stoi(tmp);

            a4 = processes[i].find(" ", a3 + 1);
            tmp = processes[i].substr(a3, a4 - a3);
            v[i].A = stoi(tmp);

            a5 = processes[i].find(" ", a4 + 1);
            tmp = processes[i].substr(a4, a5 - a4);
            v[i].B = stoi(tmp);

            v[i].used = 0;
            v[i].start = v[i].t1;
        }
        else {
            a2 = processes[i].find(" ", a1 + 1);
            tmp = processes[i].substr(a1, a2 - a1);
            v[i].t1 = stoi(tmp);

            a3 = processes[i].find(" ", a2 + 1);
            tmp = processes[i].substr(a2, a3 - a2);
            v[i].t2 = stoi(tmp);

            a4 = processes[i].find(" ", a3 + 1);
            tmp = processes[i].substr(a3, a4 - a3);
            v[i].A = stoi(tmp);

            a5 = processes[i].find(" ", a4 + 1);
            tmp = processes[i].substr(a4, a5 - a4);
            v[i].B = stoi(tmp);

            a6 = processes[i].find(" ", a5 + 1);
            tmp = processes[i].substr(a5 + 1, a6 - a5);
            v[i].C = tmp;

            v[i].used = 0;
            v[i].start = v[i].t1;
        }

    }


    int time = 0;
    int usetime = 0;
    while (1) {
        for (int i = 0; i < k; i++) {
            if (time == v[i].start && v[i].command == "write") {
                if (state == -1) {
                    v[i].wait = 1;
                    v[i].start++;
                }
                else if (state > 0) {
                    v[i].wait = 1;
                    v[i].start++;
                }
                else if (state == 0) {
                    v[i].wait = 0;
                    state = -1;
                }
            }
            
        }
        for (int i = 0; i < k; i++) {
            if (time == v[i].start && v[i].command == "read") {
                if (state >= 0) {
                    int sflag = 1;
                    for (int j = 0; j < k; j++) {
                        if (v[j].wait == 1 && v[j].command == "write") {
                            sflag = 0;
                            break;
                        }
                    }

                    if (sflag) {
                        v[i].wait = 0;
                        state++;
                    }
                    else {
                        v[i].wait = 1;
                        v[i].start++;
                    }
                }
                else if (state == -1) {
                    v[i].wait = 1;
                    v[i].start++;
                }
            }
        }

        if (state >= 1 || state == -1) {
            usetime++;
        }






        for (int i = 0; i < k; i++) {
            if (time == (v[i].start + v[i].t2 - 1) && v[i].command == "read" && v[i].used==0) {
                string sen = "";
                for (int j = v[i].A; j <= v[i].B; j++) {
                    sen += arr[j];
                }
                res.push_back({ sen, i});
                v[i].used = 1;
                state--;
            }
            else if (time == (v[i].start + v[i].t2 - 1) && v[i].command == "write" && v[i].used == 0) {
                for (int j = v[i].A; j <= v[i].B; j++) {
                    arr[j] = v[i].C;
                }

                v[i].used = 1;
                state = 0;
            }

        }






        int vflag = 1;
        for (int i = 0; i < k; i++) {
            if (v[i].used == 0) {
                vflag = 0;
                break;
            }
        }

        if (vflag)break;


       





        time++;
    }

    sort(res.begin(), res.end(), compare);
    for (int i = 0; i < res.size(); i++) {
        answer.push_back(res[i].str);
    }



    answer.push_back(to_string(usetime));

    return answer;
}

int main() {
    vector<string> arr;
    vector<string> p;

    arr.push_back("1");
    arr.push_back("2");
    arr.push_back("4");
    arr.push_back("3");
    arr.push_back("3");
    arr.push_back("4");
    arr.push_back("1");
    arr.push_back("5");

    p.push_back("read 1 3 1 2");
    p.push_back("read 2 6 4 7");
    p.push_back("write 4 3 3 5 2");
    p.push_back("read 5 2 2 5");
    p.push_back("write 6 1 3 3 9");
    p.push_back("read 9 1 0 7");

    vector<string> apd = solution(arr, p);
}