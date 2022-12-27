#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> hash;
    for(auto c : clothes){
        hash[c[1]]++;
    }
    for(auto i : hash){
        answer *= (i.second + 1);
    }
    return answer - 1;
}
