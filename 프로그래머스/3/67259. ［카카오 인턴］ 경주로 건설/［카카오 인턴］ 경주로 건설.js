function solution(board) {
    //최단거리에다가 최소 코너로 가야함..
    const dr = [1, 0, -1, 0]; // 아래, 오른쪽, 위, 왼쪽
    const dc = [0, 1, 0, -1];
       
    const N = board.length;
    
    
    const DP = Array.from(Array(N), () => Array.from(Array(N), () => Array(4).fill(Infinity)))
    
    const queue = [];
    //r, c, 방향 index, cost
    queue.push([0,0,0,0]); //아래
    queue.push([0,0,1,0]); //오른쪽
    
    while(queue.length > 0) {
        const [curR, curC, dir, cost] = queue.shift();
                
        for(let i=0;i<4;i++) {
            //다시 반대방향으로는 pass
            if(Math.abs(dir-i) === 2) {
                continue;
            }
                  
            const nextR = curR + dr[i];
            const nextC = curC + dc[i];
            //범위 체크
            if(nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) {
                continue;
            }
            //벽 체크
            if(board[nextR][nextC] === 1) {
                continue;
            }
            
            //코너인지 직선인지 계산
            let nextCost = cost;
            if(dir !== null) {
                nextCost += 100;
                if(dir % 2 === 0 && i % 2 == 1 || dir % 2 === 1 && i % 2 == 0) {
                    nextCost += 500;
                }
            }
            else {
                nextCost += 100;
            }
            
            //비용이 더 작을 경우 업데이트 해주며 큐 탐색 추가
            if(nextCost < DP[nextR][nextC][i]) {
                DP[nextR][nextC][i] = nextCost;
                queue.push([nextR, nextC, i, nextCost]);
            }
             
        }
        
    }
    

    return Math.min(...DP[N-1][N-1]);
    
}