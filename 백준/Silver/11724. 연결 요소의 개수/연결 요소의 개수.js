const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
//const arr = input[1].split("");
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  const edges = Array.from({ length: N + 1 }, () => []);
  map.map(([u, v]) => {
    edges[u].push(v);
    edges[v].push(u);
  });

  let answer = 0;

  const visited = Array.from({ length: N + 1 }, () => false);
  for (let i = 1; i < edges.length; i++) {
    if (visited[i]) continue;

    visited[i] = true;

    const queue = edges[i];

    while (queue.length > 0) {
      const cur = queue.shift();

      edges[cur].forEach((vertex) => {
        if (visited[vertex]) return;
        queue.push(vertex);
        visited[vertex] = true;
      });

      visited[cur] = true;
    }

    answer++;
  }

  console.log(answer);
}

main();
