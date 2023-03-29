#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
string answer = "";
string ret = "impossible";
bool flag = false;

int n,m,x,y,r,c,k;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char dir[4] = {'d','l','r','u'};
int get_dist(int x,int y,int a,int b){
    return abs(x-a) + abs(y-b);
}

void dfs(int cnt,int curx,int cury){
    if(!flag){
        
        int dist = get_dist(curx,cury,r,c);
        if(k - cnt - dist < 0) return;
        if((k - cnt - dist) % 2 == 1 ) return;

        if(cnt == k){
            if(curx == r && cury == c){
                flag = true;
                ret = answer;
            }
            return ;
        }
        for(int k = 0 ;k < 4 ;k++){
            int newx = curx + dx[k];
            int newy = cury + dy[k];
            if(newx > 0 && newx <= n && newy > 0 && newy <= m){
                answer += dir[k];
                dfs(cnt + 1, newx, newy);
                answer.pop_back();
            }
        }
    }
}

string solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {
    n = _n; m = _m ; x = _x; y = _y; r = _r; c = _c; k= _k;
    dfs(0,x,y);
    return ret;
}
