#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    vector<int> edges[N+1]; 
    for(int i=0;i<M;i++) {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int answer = 0;

    bool visited[N+1] = { false };

    for(int i=1; i<N+1; i++) {
        if(visited[i]) continue;
        visited[i] = true;

        queue<int> q;

        for(int j=0;j<edges[i].size(); j++) {
            int vertex = edges[i][j];
            q.push(vertex);
            visited[vertex] = true;
        }

        while(!q.empty()) {
            int curV = q.front();
            q.pop();

            for(int k=0;k<edges[curV].size(); k++) {
                int nextV = edges[curV][k];
                if(visited[nextV]) continue;
                q.push(nextV);
                visited[nextV] = true;
            }
        }

        answer++;
    }

    cout << answer;
    return 0;
}