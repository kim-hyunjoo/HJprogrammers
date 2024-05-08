const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const graph = Array.from({ length: N + 1 }, () =>
    new Array(N + 1).fill(Infinity)
  );

  map.forEach(([start, end, cost]) => {
    graph[start][end] = Math.min(graph[start][end], cost);
  });

  for (let i = 1; i <= N; i++) {
    graph[i][i] = 0;
  }

  const dist = graph[start];
  const visited = Array.from({ length: N + 1 }, () => false);

  visited[start] = true;

  const smallValueNotVisited = () => {
    let min = Infinity,
      minPos = 0;

    for (let i = 1; i <= N; i++) {
      if (dist[i] < min && !visited[i]) {
        min = dist[i];
        minPos = i;
      }
    }

    return minPos;
  };

  for (let i = 1; i < N; i++) {
    const node = smallValueNotVisited();
    visited[node] = true;
    for (let j = 1; j <= N; j++) {
      if (!visited[j]) {
        if (dist[node] + graph[node][j] < dist[j]) {
          dist[j] = dist[node] + graph[node][j];
        }
      }
    }
  }

  console.log(dist[end]);
}

main();
