const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [X] = input[0].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
//const arr = input[1].split("");
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: X + 1 });

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  for (let i = 4; i <= X; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 3 === 0) {
      dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
    }
    if (i % 2 === 0) {
      dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
    }
  }

  console.log(dp[X]);
}

main();
