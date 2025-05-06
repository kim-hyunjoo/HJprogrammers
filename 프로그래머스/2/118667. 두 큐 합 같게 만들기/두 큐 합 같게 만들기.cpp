#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long sum = 0, sum1, sum2;
    
    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    if((sum1+sum2) % 2 != 0) {
        return -1;
    }
    
    int s1 = 0;
    int e1 = queue1.size() - 1;
    int s2 = queue1.size();
    int e2 = queue1.size() * 2 - 1;
        
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    
    while(answer <= queue1.size()*2) {
        if(sum1 > sum2) {
            sum1 -= queue1[(s1++) % queue1.size()];
            sum2 += queue1[(++e2) % queue1.size()];
        }
        else if(sum1 < sum2) {
            sum1 += queue1[(++e1) % queue1.size()];
            sum2 -= queue1[(s2++) % queue1.size()];
        }
        else {
            return answer;
        }
        answer++;
    }
    
    return -1;
}