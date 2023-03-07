#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int N, M;
int mat[101][101] ;
bool vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x, int y){
    int ret = mat[x][y];
    for(int k = 0 ; k < 4 ; k++){            
        if(x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < M){
            if(!vis[x + dx[k]][y + dy[k]] && mat[x + dx[k]][y + dy[k]]){
                vis[x + dx[k]][y + dy[k]] = true;
                ret += dfs(x + dx[k], y + dy[k]);
            }
        }
    }
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M; j++){
            if(maps[i][j] == 'X'){
                mat[i][j] = 0;
            }
            else{
                mat[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j < M ; j++){ 
            if(!vis[i][j] && mat[i][j]){
                vis[i][j] = true;
                answer.push_back(dfs(i,j));
            }
        }
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}
