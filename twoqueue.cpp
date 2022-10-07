#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> p, vector<int> q) {
    int answer = -2;
    long long ptot = 0, qtot = 0;
    int pi=0,qi=0 , len;
    len = p.size();
    for(int i = 0 ; i < len; i++){
        ptot += p[i];
        qtot += q[i];
        p.push_back(q[i]);
        q.push_back(p[i]);;
    }
    if((ptot + qtot) % 2 == 1)
        return -1;
    while(pi != p.size() && qi != q.size()){
        if(ptot == qtot){
            break;
        }
        else if(ptot > qtot){
            ptot -= p[pi];
            qtot += p[pi++];
        }
        else{
            qtot -= q[qi];
            ptot += q[qi++];
        }
    }
    if(ptot == qtot)
        return (pi + qi);
    else
        return -1;
}
