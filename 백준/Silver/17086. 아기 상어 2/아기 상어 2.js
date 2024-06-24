const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

//const [N] = input[0].split(" ").map(Number);
const [N, M] = input[0].split(" ").map(Number);
//const [M] = input[2].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

const dr = [1, 0, -1, 0, -1, 1, -1, 1];
const dc = [0, 1, 0, -1, -1, -1, 1, 1];
function main() {
  let answer = 0;

  const queue = [];
  const dist = Array.from({ length: N }, () => new Array(M).fill(0));
  
  for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
      if (map[r][c] === 1) {
        queue.push([r, c]);
      }
    }
  }

  while (queue.length > 0) {
    const [curR, curC] = queue.shift();

    for (let i = 0; i < 8; i++) {
      const nextR = curR + dr[i];
      const nextC = curC + dc[i];

      if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
      if (map[nextR][nextC] === 1) continue;
      if (dist[nextR][nextC] === 0) {
        dist[nextR][nextC] = dist[curR][curC] + 1;
        queue.push([nextR, nextC]);
      }
    }
  }

  console.log(Math.max(...dist.flat()));
}

main();
