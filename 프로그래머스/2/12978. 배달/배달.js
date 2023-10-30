function solution(N, road, K) {
    const graph = Array.from({length: N+1}, 
        (v, r) => { return Array.from({length: N+1}, 
            (v, c) => r === c ? 0 : Number.MAX_SAFE_INTEGER
        )}
    )

    road.forEach(([start, end, distance]) => {
        if(graph[start][end] < distance) { //더 작은 값 이미 들어있으면 continue
            return;
        }
        graph[start][end] = distance;
        graph[end][start] = distance;
    })
   
    const visit = [1]; //방문한 노드
    
    const distance = graph[1]; //1에서부터의 최단거리를 재기 위함
    
    const choose = () => {
        let min = Number.MAX_SAFE_INTEGER;
        let minPos = -1;
        for(let i=1;i<N+1;i++) {
            if(distance[i] < min && !visit.includes(i) ) {
                min = distance[i];
                minPos = i;
            }
        }
        return minPos;
    }
    
    //다익스트라
    for(let i=1;i<N;i++) {
        const u = choose();//가장 distance에서 작은 값
        visit.push(u); //방문 체크
        for(let w=1;w<N+1;w++) {
            if(!visit.includes(w)) { // 최단거리 업데이트
                if(distance[u] + graph[u][w] < distance[w]) {
                    distance[w] = distance[u] + graph[u][w]
                }
            }
        }
    }
        
    return distance.filter(dist=>dist <= K).length;
}