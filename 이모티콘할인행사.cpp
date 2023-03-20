#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> point;

int dis[4] = {10,20,30,40};
int esize;
vector <int> choice;
vector<vector<int>> users;
vector<int> emot;
point ans = {-1,-1};

void solve(){
    point local = make_pair(0,0);
    for(auto u : users){
        int uth = u[0];
        int up = u[1];
        int buy = 0;
        bool flag = false;
        for(int i = 0 ; i < esize ;i++){
            if(choice[i] >= uth){
                buy += emot[i]/100 * (100 - choice[i]);
                if(buy >= up){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true)
            local.first += 1;
        else 
            local.second += buy;
    }
    if(ans.first < local.first){
        ans.first = local.first;
        ans.second = local.second;
    }
    else if (ans.first == local.first && ans.second < local.second)
        ans.second = local.second;
}

void dfs(){
    if(choice.size() == esize){
        solve();
        return;
    }
    for(int i = 0 ; i < 4 ;i++){
        choice.push_back(dis[i]);
        dfs();
        choice.pop_back();
    }
    return;
}

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    vector<int> answer;
    users = _users;
    emot = _emoticons;
    esize = emot.size();
    dfs();
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}
