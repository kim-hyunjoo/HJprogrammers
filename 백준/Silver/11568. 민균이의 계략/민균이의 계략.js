const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let [N] = input[0].split(" ").map(Number);
const numbers = input[1].split(" ").map(Number);
//const [M] = input[1].split(" ").map(Number);
//const map = input.slice(2, M + 2).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: N }, () => 1);

  for (let i = 0; i < N; i++) {
    for (let j = i - 1; j >= 0; j--) {
      if (numbers[i] > numbers[j]) {
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }
  }

  console.log(Math.max(...dp));
}

main();
