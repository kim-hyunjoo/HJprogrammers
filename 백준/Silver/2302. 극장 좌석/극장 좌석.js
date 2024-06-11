const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
//const [R, C, K] = input[0].split(" ").map(Number);
const [M] = input[1].split(" ").map(Number);
const arr = input.slice(2).map(Number);
//const [M] = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(""));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  const dp = Array.from({ length: N + 1 }, () => 1);
  dp[1] = 1;
  dp[2] = 2;
  for (let i = 3; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  let answer = 1;
  let prev = 0;

  arr.forEach((el) => {
    answer *= dp[el - prev - 1];
    prev = el;
  });
  answer *= dp[N - prev];

  console.log(answer);
}
main();
