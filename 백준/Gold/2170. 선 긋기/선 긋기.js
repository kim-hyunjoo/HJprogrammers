const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const test_case = Number(input.shift();
//const [test_case] = input[0].split(" ").map(Number);
const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  map.sort((a, b) => a[0] - b[0]);
  let answer = 0;
  let line = map[0];

  for (let i = 1; i < N; i++) {
    const [start, end] = line;
    const [curStart, curEnd] = map[i];
    if (end < curStart) {
      line = map[i];
      answer += end - start;
    } else {
      line = [start, Math.max(end, curEnd)];
    }
  }
  answer += line[1] - line[0];

  console.log(answer);
}

main();
