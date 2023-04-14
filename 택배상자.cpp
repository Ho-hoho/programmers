#include <string>
#include <vector>
#include <stack>

using namespace std;

stack <int> s;

int solution(vector<int> order) {
    int N = order.size();
    
    int idx = 0;
    for(int i = 1; i <= N ; i++){
        if(i < order[idx]) s.push(i);
        else if (i == order[idx]) idx++;
        else if (!s.empty() && s.top() == i) {
            idx++;
            s.pop();
        }
        else break;
        while(!s.empty() && s.top() == order[idx]){
            idx++;
            s.pop();
        }
    }
    return idx;
}
