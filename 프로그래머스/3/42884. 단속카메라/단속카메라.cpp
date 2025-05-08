#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    int end = -30001;
    
    for(int i=0;i<routes.size();i++) {  
        if(routes[i][0] <= end) {
            continue;
        }
        else {
            end = routes[i][1];
            answer++;
        }
    }
    return answer;
}