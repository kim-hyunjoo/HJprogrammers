//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor;
    
    //우선 brwon + yellow 의 약수를 구해보자
    //sqrt(brwon+yellow) 까지의 약수만 구해서 그 수들로 brown + yellow 를 나누면 약수구하기가능~
    
    //brown + yellow == width * height
    int N = brown + yellow;

    for(int i = 1; i<=sqrt(N); i++) {
        if(N%i==0) {//나누어 떨어지면 i는 약수 
            divisor.push_back(i);
        }
    }
    sort(divisor.begin(), divisor.end());

    //brown 가로 - 2 == yellow 가로
    //brown 세로 - 2 == yellow 세로
    for (int height : divisor) {
        int width = N/height; //a : 세로 b : 가로
        if(height-2 > 0 && width-2 > 0 && (height-2)*(width-2) == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}

int main() {
    for(int i : solution(10,2))
        cout<<i<<endl;
    cout<<"---"<<endl;
    for(int i : solution(8,1))
        cout<<i<<endl;
    cout<<"---"<<endl;
    for(int i : solution(24,24))
        cout<<i<<endl;
    cout<<"---"<<endl;
}