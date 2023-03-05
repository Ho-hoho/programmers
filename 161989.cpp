#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int idx = 0;
    int pos;
    while(idx < section.size()){
        pos = section[idx++];
        while(idx < section.size() && pos + m - 1 >= section[idx])
            idx++;
        answer++;
    }
    return answer;
}
