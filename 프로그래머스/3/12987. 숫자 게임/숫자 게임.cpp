#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i < A.size(); i++) {
        if(A[i] < B[i]) {
            answer++;
        }
        else {
            int temp = B[B.size()-1];
            B.pop_back();
            B.insert(B.begin()+i, temp);
            
        }
    }
    
    return answer;
}