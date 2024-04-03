const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

const dr = [1, 0];
const dc = [0, 1];

function main() {
  let answer = "Hing";
  const queue = [[0, 0]];
  const visited = Array.from({ length: N }, () => new Array(N).fill(false));
  visited[0][0] = true;

  while (queue.length > 0) {
    const [curR, curC] = queue.shift();

    const curDist = map[curR][curC]; // 이동할 거리

    //도착지에 도착한 경우
    if (curDist === -1) {
      answer = "HaruHaru";
      break;
    }

    for (let i = 0; i < 2; i++) {
      const nextR = curR + dr[i] * curDist;
      const nextC = curC + dc[i] * curDist;
      //만약 범위를 벗어나거나 이미 방문한 적 있다면 탐색x
      if (nextR >= N || nextC >= N || visited[nextR][nextC]) {
        continue;
      }

      queue.push([nextR, nextC]);
      visited[nextR][nextC] = true;
    }
  }
  console.log(answer);
}

main();
