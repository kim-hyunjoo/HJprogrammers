const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
//const [N, M] = input[0].split(" ").map(Number);
//const [M] = input[2].split(" ").map(Number);
const arr = input.slice(1).map(Number);
//const arr = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: N + 1 }, () => 0);

  dp[1] = arr[0];
  dp[2] = arr[0] + arr[1];

  for (let i = 3; i <= N; i++) {
    dp[i] = Math.max(
      dp[i - 1],
      dp[i - 3] + arr[i - 2] + arr[i - 1],
      dp[i - 2] + arr[i - 1]
    );
  }
  console.log(dp[N]);
}

main();
