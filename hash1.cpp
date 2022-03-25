#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int i;
    for(i=0;i<completion.size();i++) {
        if(participant[i] != completion[i]) 
            return participant[i];
            
    }
    
    return participant[i];

}

int main() {
    vector<string> participant1 = {"leo", "kiki", "eden"};
    vector<string> participant2 = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> participant3 = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion1 =  { "eden", "kiki" };
    vector<string> completion2 =  { "josipa", "filipa", "marina", "nikola" };
    vector<string> completion3 =  { "stanko", "ana", "mislav" };

    cout<<solution(participant1, completion1)<<endl;
    cout<<solution(participant2, completion2)<<endl;
    cout<<solution(participant3, completion3)<<endl;
    cout<<"git test"<<endl;
}