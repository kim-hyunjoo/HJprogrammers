#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int start = 1;
    int end;
    
    for(int station : stations) {
        end = station-w-1; 
        answer += (int)ceil((double)(end-start+1)/(double)(2*w+1));
        start = station+w+1;
    }
    end = n;
    answer += (int)ceil((double)(end-start+1)/(double)(2*w+1));

    return answer;
}