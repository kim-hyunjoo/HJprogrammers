//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count = {0,0,0};

    vector<int> human1 = {1,2,3,4,5};
    vector<int> human2 = {2,1,2,3,2,4,2,5};
    vector<int> human3 = {3,3,1,1,2,2,4,4,5,5};

    for(int i=0;i<answers.size();i++) {
        if(answers[i]==human1[i%human1.size()]) 
            count[0]++;
        if(answers[i]==human2[i%human2.size()])
            count[1]++;         
        if(answers[i]==human3[i%human3.size()])
            count[2]++;
        
    }
    int m = max(max(count[0],count[1]),count[2]);

    for(int i=0;i<3;i++) {
        if(count[i]==m)
            answer.push_back(i+1);
    }


    return answer;
}

int main() {
    vector<int> answers1 = {1,2,3,4,5};
    vector<int> answers2 = {1,3,2,4,2};
    //vector<int> result1 = solution(answers1);
    for(int i : solution(answers1))
        cout<<i<<endl;
    for(int i : solution(answers2))
        cout<<i<<endl;
}