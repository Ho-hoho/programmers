#include <string>
#include <vector>

using namespace std;
int w[8] = {0,3,2,1,0,1,2,3};
int arr[4][2] = {0};
string test[4] = {"RT","CF","JM","AN"};
void solve (string s, int c){
    if(s == "TR"){
        if(c >= 1 && c <=3){
            arr[0][1]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[0][0]+= w[c];
        }
    }
    else if (s == "RT"){
        if(c >= 1 && c <=3){
            arr[0][0]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[0][1]+= w[c];
        }
    }
    else if(s == "FC"){
        if(c >= 1 && c <=3){
            arr[1][1]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[1][0]+= w[c];
        }
    }else if(s == "CF"){
        if(c >= 1 && c <=3){
            arr[1][0]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[1][1]+= w[c];
        }
    }else if(s == "MJ"){
        if(c >= 1 && c <=3){
            arr[2][1]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[2][0]+= w[c];
        }
    }else if(s == "JM"){
        if(c >= 1 && c <=3){
            arr[2][0]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[2][1]+= w[c];
        }
    }else if(s == "NA"){
        if(c >= 1 && c <=3){
            arr[3][1]+= w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[3][0] += w[c];
        }
    }else if(s == "AN"){
        if(c >= 1 && c <=3){
            arr[3][0] += w[c];
        }
        else if(c >= 5 && c <= 7){
            arr[3][1] += w[c];
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int len = survey.size();
    for(int i = 0 ; i < len ; i++){
        solve(survey[i],choices[i]);
    }
    for(int i = 0 ; i< 4;i++){
        if(arr[i][0] >= arr[i][1])
            answer += (test[i][0]);
        else
            answer += (test[i][1]);
    }
    return answer;
}
