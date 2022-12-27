#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> arr) {
    bool answer = true;
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i < arr.size() - 1; i++ ){
        if(arr[i] == arr[i+1].substr(0,arr[i].size())){
            answer = false;
            break;
        }
    }
    return answer;
}
