#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

unordered_map<string,int> map; // 코스조합, 개수 저장할 map

void dfs(int nextIdx, string order, string curOrder) {   
    if(curOrder.length() >= 2) {
        map[curOrder]++;
        if(curOrder.length() == order.length()) return;
    }
    
    for(int i=nextIdx;i<order.length();i++) {
        dfs(i+1, order, curOrder + order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string order : orders) {
        // orders 알파벳 순 정렬
        sort(order.begin(), order.end());
        dfs(0, order, "");
    }
    
    for(int c : course) {
        int max_order = 2;
        unordered_map<string,int>::iterator it;
        
        for(it = map.begin(); it != map.end(); it++) {
            if(it->second >= 2 && it->first.length() == c) {
                max_order = max(max_order, it->second);
            }   
        }
        
        for(it = map.begin(); it != map.end(); it++) {
            if(it->first.length() == c && it->second == max_order) {
                answer.push_back(it->first);
            }   
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}