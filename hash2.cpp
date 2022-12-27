#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map <int,int> hash;
    for(auto i : nums){
        hash[i]++;
    }
    for(auto i : hash){
        answer++;
    }
    answer = nums.size()/2 > answer? answer : nums.size()/2; 
    return answer;
}
