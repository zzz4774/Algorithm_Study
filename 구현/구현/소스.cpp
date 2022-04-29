#include<iostream>
#include<string>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node {
    string s;
    int v;
    int c;
    int a;
};
bool compare(node a, node b) {
    return a.v > b.v;
}

bool compare2(node a, node b) {
    if (a.a == b.a)return a.v > b.v;
    return a.a < b.a;
}
map <string, int> song;
vector<node> list;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<node> ge;
    for (int i = 0; i < genres.size(); i++) {
        list.push_back({ genres[i], plays[i], i, 0 });
        song[genres[i]] += plays[i];
    }

    for (auto it = song.begin(); it != song.end(); it++) {
        ge.push_back({ it->first, it->second, 0,0 });
    }

    sort(ge.begin(), ge.end(), compare);

    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < ge.size(); j++) {
            if (list[i].s == ge[j].s) {
                list[i].a = j;
                break;
            }
        }
    }

    sort(list.begin(), list.end(), compare2);
    if (list.size() % 2 == 0) {
        for (int i = 0; i < list.size(); i++) {
            answer.push_back(list[i].c);
        }
    }
    else {
        for (int i = 0; i < list.size() - 1; i++) {
            answer.push_back(list[i].c);
        }
    }



    return answer;
}
int main() {
    vector<string> genre;
    genre.push_back("classic");
    genre.push_back("pop");
    genre.push_back("classic");
    genre.push_back("classic");
    genre.push_back("pop");
    vector<int> plays;
    plays.push_back(500);
    plays.push_back(600); 
    plays.push_back(150); 
    plays.push_back(800); 
    plays.push_back(2500);
    vector<int> a;
    a = solution(genre, plays);
}