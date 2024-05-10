const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: N + 1 }, () => -1);
  dp[3] = 1;
  dp[5] = 1;

  for (let i = 6; i <= N; i++) {
    if (dp[i - 3] === -1 && dp[i - 5] === -1) continue;
    if (dp[i - 3] === -1) {
      dp[i] = dp[i - 5] + 1;
    } else if (dp[i - 5] === -1) {
      dp[i] = dp[i - 3] + 1;
    } else {
      dp[i] = Math.min(dp[i - 3], dp[i - 5]) + 1;
    }
  }

  console.log(dp[N]);
}

main();
