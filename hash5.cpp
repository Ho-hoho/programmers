#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool cmp (pair<string,int>& a, pair<string,int>& b){
    if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string, int> hashp;
    unordered_map <string, pair<int,int>> hashi;
    
    for(int i = 0 ; i < genres.size(); i++){
        string k = genres[i];
        hashp[k] += plays[i];
        if(hashi.find(k) == hashi.end()){
            hashi[k] = {-1,-1};
        }
        if(hashi[k].first!= -1 && plays[hashi[k].first] < plays[i]){
            hashi[k].second = hashi[k].first;
            hashi[k].first = i;
        }
        else if (hashi[k].second != -1 && plays[hashi[k].second]< plays[i]){
            hashi[k].second = i;
        }
        
        if(hashi[k].first == -1){
            hashi[k].first = i;
        }
        else if(hashi[k].second == -1){
            hashi[k].second = i;
        }
    }
    vector<pair<string,int>> vec( hashp.begin(), hashp.end() );
    sort(vec.begin(), vec.end(),cmp);
    for(auto i : vec){
        if(hashi[i.first].first != -1){
            answer.push_back(hashi[i.first].first);
            if(hashi[i.first].second != -1)
                answer.push_back(hashi[i.first].second);
        } 
    }
    
    return answer;
}
