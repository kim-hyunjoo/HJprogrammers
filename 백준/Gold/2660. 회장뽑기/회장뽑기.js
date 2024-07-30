const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
//const [M] = input[0].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
map.pop();
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const graph = Array.from({ length: N + 1 }, () =>
    new Array(N + 1).fill(Infinity)
  );

  map.forEach(([start, end]) => {
    graph[start][end] = 1;
    graph[end][start] = 1;
  });

  //플로이드워셜
  for (let mid = 1; mid <= N; mid++) {
    for (let start = 1; start <= N; start++) {
      for (let end = 1; end <= N; end++) {
        graph[start][end] = Math.min(
          graph[start][end],
          graph[start][mid] + graph[mid][end]
        );
      }
    }
  }

  for (let start = 1; start <= N; start++) {
    for (let end = 1; end <= N; end++) {
      if (start === end) {
        graph[start][end] = 0;
      }
    }
  }

  const scores = [Infinity];

  for (let i = 1; i <= N; i++) {
    let max = 0;
    for (let j = 1; j <= N; j++) {
      max = Math.max(max, graph[i][j]);
    }
    scores.push(max);
  }

  const minScore = Math.min(...scores);
  const count = scores.filter((score) => score === minScore).length;
  const numbers = [];
  scores.map((score, index) => {
    if (score === minScore) {
      numbers.push(index);
    }
  });

  console.log(minScore, count);
  console.log(numbers.join(" "));
}

main();
