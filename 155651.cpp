#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int,int> point;

vector <point> arr;
priority_queue <int,vector<int>,greater<int>> pq;

int solution(vector<vector<string>> book_time) {
    int answer;
    for(int i = 0 ; i < book_time.size() ; i++){
        int s, e;
        string str = book_time[i][0];
        s = 60 * (str[0]*10 + str[1]) + str[3]*10 + str[4];
        str = book_time[i][1];
        e = 60 * (str[0]*10 + str[1]) + str[3]*10 + str[4] + 10;
        arr.push_back(make_pair(s,e));
    }
    sort(arr.begin(),arr.end());
    pq.push(arr[0].second); answer = 1;
    for(int i = 1 ; i < arr.size(); i++){
        int curs = arr[i].first;
        int cure = arr[i].second;
        if(!pq.empty()){
            if(curs >= pq.top())
                pq.pop();
            else answer += 1;
        }
        pq.push(cure);
    }
    return answer;
}
