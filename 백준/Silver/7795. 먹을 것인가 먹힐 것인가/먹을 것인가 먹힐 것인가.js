const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

//const [n, m, t] = input[0].split(" ").map(Number);
const T = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  for (let t = 0; t < T; t++) {
    let count = 0;
    const [N, M] = map[t * 3];
    const A = map[t * 3 + 1];
    const B = map[t * 3 + 2];
    for (let n = 0; n < N; n++) {
      for (let m = 0; m < M; m++) {
        if (A[n] > B[m]) {
          count++;
        }
      }
    }
    console.log(count);
  }
}

main();
