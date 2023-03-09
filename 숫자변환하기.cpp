#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> point;

bool vis[1000001];
queue <point> q;

int solution(int x, int y, int n) {
    int answer = 0;
    if(x == y) return 0;
    q.push(make_pair(x,0));
    while(!q.empty()){
        int cur = q.front().first;
        int curt = q.front().second;
        q.pop();
        if(cur + n <= y && !vis[cur + n]){
            vis[cur + n] = true;
            if(cur + n == y)
                return curt + 1;
            q.push(make_pair(cur + n ,curt + 1));
        }
        if(cur * 2 <= y && !vis[cur * 2]){
            vis[cur * 2] = true;
            if(cur * 2 == y)
                return curt + 1;
            q.push(make_pair(cur * 2 ,curt + 1));
        }
        if(cur * 3 <= y && !vis[cur * 3]){
            vis[cur * 3] = true;
            if(cur * 3 == y)
                return curt + 1;
            q.push(make_pair(cur * 3 ,curt + 1));
        }
    }
    return -1;
}
