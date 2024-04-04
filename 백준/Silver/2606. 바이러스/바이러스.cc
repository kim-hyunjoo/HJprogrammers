#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
bool visited[101] = {false};
int answer = 0;

void dfs(int item) {
    visited[item] = true;
    answer++;
    for(int it : vec[item]) {
        if(visited[it] == false) {
            dfs(it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;

    cin >> V;
    cin >> E;
    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        vec[start].push_back(end);
        vec[end].push_back(start);
    }

    dfs(1);

    cout << answer-1;

    return 0;
}