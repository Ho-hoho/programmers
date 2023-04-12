#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    pair<int,int> ans = make_pair(0, 1987654321);
    int s = 0, e = 0;
    int N = arr.size();
    vector<int> dp (N);
    dp[0] = arr[0];
    for(int i = 1 ;i < N ;i++){
        dp[i] = dp[i-1] + arr[i];
    }
    while(s <= e && e < N){
        int psum = dp[e] - dp[s] + arr[s];
        if(psum == k){
            if(e - s < ans.second - ans.first){
                ans = make_pair(s,e);
            }
            s++; e++;
        }
        else if (psum > k) s++;
        else e++;
    }
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}
