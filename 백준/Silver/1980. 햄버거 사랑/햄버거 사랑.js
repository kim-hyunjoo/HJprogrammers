const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [n, m, t] = input[0].split(" ").map(Number);
//const N = Number(input[0]);

//const arr = input[1].split(" ").map(Number);
//const arr = input.slice(1);
//const map = input.slice(1).map((_) => _.trim().split(" ").map(Number));

function main() {
  let time = t;
  let min = Math.min(n, m);
  let max = Math.max(n, m);

  const arr = [];

  let max_count = 0;
  while (max * max_count <= time) {
    let min_time = time - max * max_count;
    let min_count = Math.floor(min_time / min);
    let coke = min_time % min;
    arr.push([max_count + min_count, coke]);
    max_count++;
  }
  arr.sort((a, b) => a[1] - b[1]);
  console.log(arr[0].join(" "));
}

main();
