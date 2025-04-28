#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    
    vector<string> dict = { words[0] };
    
    for(int i=1; i<words.size(); i++) {
        if(find(dict.begin(), dict.end(), words[i]) == dict.end() && 
          words[i-1].back() == words[i].front()) {
            dict.push_back(words[i]);
        }
        
        else {
            int a = (i + 1) % n;
            if(a == 0) {
                a = n;
            }
            int b = i / n + 1;
            answer = { a, b };
            break;
        }
    }

    return answer;
}