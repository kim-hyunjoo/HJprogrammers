#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> graph;
bool isVisited[10001];
vector<string> answer;
bool isAnswer = false;

void DFS(string curAirport, int depth) {
    answer.push_back(curAirport);
    
    if(depth == graph.size()) {
        isAnswer = true;
    }
    
     for(int i=0; i<graph.size(); i++) {
         if(!isVisited[i] && graph[i][0] == curAirport) {
                 isVisited[i] = true;
                 DFS(graph[i][1], depth+1);
                 if(!isAnswer) {
                     answer.pop_back();
                     isVisited[i] = false;
                 } 
         }
         
     }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    graph = tickets;
    DFS("ICN", 0);
    
    return answer;
}