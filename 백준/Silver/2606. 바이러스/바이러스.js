const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [V] = input[0].split(" ").map(Number);
const map = input.slice(2).map((_) => _.trim().split(" ").map(Number));

const edge = Array.from({ length: V + 1 }, () => []);
const visited = Array.from({ length: V + 1 }, () => false);

function dfs(item) {
  visited[item] = true;
  edge[item].forEach((v) => {
    if (!visited[v]) {
      dfs(v);
    }
  });
}

function main() {
  map.forEach(([start, end]) => {
    edge[start].push(end);
    edge[end].push(start);
  });

  dfs(1);

  console.log(visited.filter((el) => el === true).length - 1);
}

main();
