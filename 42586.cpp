#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pivot = 0;
    int n = progresses.size();
    while(pivot < n){
        for(int i=0;i<n;i++){
            progresses[i] += speeds[i];
        }
        if(progresses[pivot] >= 100){
            int prev = pivot++;
            for(int i=pivot;i<n;i++){
                if(progresses[i] < 100) break;
                pivot++;
            }
            answer.push_back(pivot-prev);
        }
    }
    
    return answer;
}
