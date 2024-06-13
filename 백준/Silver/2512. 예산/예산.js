const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N] = input[0].split(" ").map(Number);
//const [R, C, K] = input[0].split(" ").map(Number);
const [M] = input[2].split(" ").map(Number);
//const arr = input.slice(1).map(Number);
const arr = input[1].split(" ").map(Number);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));
//const [start, end] = input[M + 2].split(" ").map(Number);

function main() {
  arr.sort((a, b) => a - b);

  let left = 0;
  let right = arr[N - 1];
  let answer = 0;

  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    let sum = 0;
    for (let i = 0; i < N; i++) {
      sum += Math.min(mid, arr[i]);
      if (sum > M) break;
    }
    if (sum > M) {
      right = mid - 1;
    } else {
      left = mid + 1;
      answer = mid;
    }
  }

  console.log(answer);
}

main();
