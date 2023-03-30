#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int bin[100] = {0};

bool check(long long s, long long e){
    if(s + 1 == e) return true;
    long long mid = (s + e) / 2;
    if(bin[mid] == 0){
        for(int i = s ; i < e ;i++){
            if(bin[i] == 1)
                return false;
        }
        return true;
    }
    return check(s,mid) && check(mid+1,e);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long num : numbers){
        long long k = 0;
        long long len = 1;
        memset(bin,0,sizeof(bin));
        while(pow(2,k) <= num){
            k += 1;
        }
        while(len < k){
            len *= 2;
        }
        len -= 1;
        for(int i = len - 1 ; i >= 0 ;i--){
            bin[i] = num % 2;
            num /= 2;
        }
        if(check(0,len)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}
