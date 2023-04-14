#include <string>
#include <vector>
#include <cstring>

using namespace std;

int larr[1000001];
int rarr[1000001];
int vis[10001];

int solution(vector<int> topping) {
    int answer = 0;
    int N = topping.size();
    if(N == 1) return 0;
    
    larr[0] = 1; vis[topping[0]] = true;
    for(int i = 1 ; i < N; i++){
        if(!vis[topping[i]]) {
            larr[i] = larr[i-1] + 1;
            vis[topping[i]] = true;
        }
        else larr[i] = larr[i-1];
    }
    memset(vis,false,sizeof(vis));
    
    rarr[N-1] = 1; vis[topping[N-1]] = true;
    for(int i = N - 2 ; i >= 0; i--){
        if(!vis[topping[i]]) {
            rarr[i] = rarr[i+1] + 1;
            vis[topping[i]] = true;
        }
        else rarr[i] = rarr[i+1];
    }
    
    for(int i = 1 ; i < N - 1 ;i++){
        if(larr[i] == rarr[i+1])
            answer++;
    }
    return answer;
}
