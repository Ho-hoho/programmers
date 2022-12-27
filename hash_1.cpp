#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string,int> hash;
    for(auto i : participant){
        hash[i]++;
    }
    for(auto i : completion){
        hash[i]--;
    }
    for(auto i : hash){
        if(i.second == 1)
            answer = i.first;
    }
    return answer;
}
