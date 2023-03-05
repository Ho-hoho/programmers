#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
typedef pair<int,int> point;



stack <point> s;

vector<int> solution(vector<int> numbers) {
    int N = numbers.size();
    vector<int> answer;
    for(int i = 0 ; i < N ;i++)
        answer.push_back(-1);
    for(int i = 0 ; i < N ;i++){
        int cur = numbers[i];
        while(!s.empty()){
            point t = s.top();
            if(t.first < cur){
                answer[t.second] = cur;
                s.pop();
            }
            else break;
        }
        s.push(make_pair(cur,i));
        
    }
    return answer;
}
