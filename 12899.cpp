#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    stack <int> s;
    int a;
    while(n > 0){
        s.push((n-1)%3);
        n = (n-1)/3;
    }
    while(!s.empty()){
        a = s.top();s.pop();
        switch(a){
            case 0 :
                answer += "1";
                break;
            case 1 :
                answer += "2";
                break;
            case 2 :
                answer += "4";
                break;
        }
    }
    return answer;
}
