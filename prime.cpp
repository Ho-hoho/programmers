#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

bool prime(long long n){
    if(n == 1 || n == 0) return false;
    bool ret = true;
    for(int i= 2; i<= sqrt(n);i++){
        if(n % i == 0) {ret = false; break;}
    }
    return ret;
}


int solution(int n, int k) {
    int answer = 0;
    stack <int> s;
    while(n > 0){
        s.push(n % k);
        n /= k;
    }
    while(1){
        vector<int> arr; 
        while(!s.empty()){
            if(s.top() == 0) {
                s.pop();
                break;
            }
            arr.push_back(s.top()); 
            s.pop();

        }

        if(arr.size() == 0){
            if(s.empty()) break;
            else continue;
        } 
        long long cur = 0 , t= 1;
        for(int i=arr.size()-1;i>=0;i--){
            cur += arr[i] * t;
            t*=10;
        }
        if(prime(cur) ) answer++;

    }
    return answer;
}
