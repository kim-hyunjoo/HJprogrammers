const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [T] = input[0].split(" ").map(Number);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function factorial(N) {
  let sum = 1;
  for (let i = 1; i <= N; i++) {
    sum = sum * i;
  }
  return sum;
}

function main() {
  for (let test_case = 0; test_case < T; test_case++) {
    let answer;
    const [N, M] = map[test_case];
    answer = Math.round(factorial(M) / (factorial(M - N) * factorial(N)));
    console.log(answer);
  }
}

main();
