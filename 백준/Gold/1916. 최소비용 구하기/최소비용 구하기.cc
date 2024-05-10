#include <iostream>
#include <vector>
using namespace std;

int N, M;
int graph[1001][1001];
bool visited[1001];
int dist[1001];

int smallCostIndex() {
    int min = 987654321;
    int minPos = 0;
    for(int i=1; i<=N; i++) {
        if(dist[i] < min && !visited[i]) {
            min = dist[i];
            minPos = i;
        }
    }
    return minPos;
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    cin >> N >> M;
    fill(&graph[0][0], &graph[N][N+1], 987654321);

    for(int i=0; i<M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start][end] = min(graph[start][end], cost);
    }

    
    for(int i=1; i<=N; i++) {
        graph[i][i] = 0;
    }

    int start, end;
    cin >> start >> end;

    for(int i=1;i<=N;i++) {
        dist[i] = graph[start][i];
    }

    fill_n(visited, N+1, false);
    visited[start] = true;

    for(int i = 1; i < N; i++) {
        int node = smallCostIndex();
        visited[node] = true;

        for(int j=1; j<=N; j++) {
            if(!visited[j]) {
                if(dist[node] + graph[node][j] < dist[j]) {
                    dist[j] = dist[node] + graph[node][j];
                }
            }
        }
    }

    cout << dist[end];


    return 0;
}