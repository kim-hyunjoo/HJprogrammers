#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int x=0;x<=d;x+=k) {
        long long maxY = sqrt((long)d*d - (long)x*x);
        answer += floor(maxY/k) + 1;
    }
    
    return answer;
}