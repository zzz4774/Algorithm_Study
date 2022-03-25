#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<string> arr;

vector<string> solution(vector<string> goods) {
    vector<string> answer;

    for (int i = 0; i < goods.size(); i++) {
        int flag = 0;
        int cnt = 0;
        string sen = "";
        for (int j = 1; j <= goods[i].size(); j++) {
            vector<string> v;
            for (int k = 0; k <= goods[i].size() - j; k++) {
                string tmp = goods[i].substr(k, j);
                int mflag = 1;

                for (int m = 0; m < goods.size(); m++) {
                    if (m != i) {
                        int a = goods[m].find(tmp);
                        if (a != -1) {
                            mflag = 0;
                            break;
                        }
                    }

                }


                if (mflag) {
                    v.push_back(tmp);
                    flag = 1;
                }


            }
            if (!v.empty()) {
                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
                for (int i = 0; i < v.size() - 1; i++) {
                    sen += v[i];
                    sen += " ";
                }
                sen += v[v.size() - 1];
                v.clear();
            }



            if (flag)break;
        }

        if (sen == "") {
            answer.push_back("None");
        }
        else {
            answer.push_back(sen);
        }




    }



    return answer;
}



int main() {
    vector<string> goods;
    goods.push_back("pencil");
    goods.push_back("penci");
    goods.push_back("contrabase");
    goods.push_back("picturelist");

    arr = solution(goods);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
   
}