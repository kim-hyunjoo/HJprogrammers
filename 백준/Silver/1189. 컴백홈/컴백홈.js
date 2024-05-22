const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [R, C, K] = input[0].split(" ").map(Number);
//const numbers = input[1].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(""));
//const [start, end] = input[M + 2].split(" ").map(Number);

const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];
const visited = Array.from({ length: R }, () => new Array(C).fill(false));
let answer = 0;

const dfs = (curR, curC, distance) => {
  if (distance >= K) {
    if (curR === 0 && curC === C - 1) {
      answer++;
    }
    return;
  }
  for (let i = 0; i < 4; i++) {
    const nextR = curR + dr[i];
    const nextC = curC + dc[i];

    if (
      nextR < 0 ||
      nextC < 0 ||
      nextR >= R ||
      nextC >= C ||
      map[nextR][nextC] === "T" ||
      visited[nextR][nextC] === true
    ) {
      continue;
    }
    visited[nextR][nextC] = true;
    dfs(nextR, nextC, distance + 1);
    visited[nextR][nextC] = false;
  }
};

function main() {
  visited[R - 1][0] = true;
  dfs(R - 1, 0, 1);
  console.log(answer);
}

main();
