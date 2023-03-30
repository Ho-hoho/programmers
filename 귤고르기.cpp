#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef pair<int,int> point;
unordered_map<int,int> m;

bool cmp (const point &a,const point &b){
    return a.second > b.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto i : tangerine){
        m[i] += 1;
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(auto i : v){
        k -= i.second;
        answer++;
        if(k <= 0) break;
    }
    return answer;
}
